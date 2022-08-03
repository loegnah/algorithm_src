// n 최대값이 16이라 dp로 품.

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MX_INT = 50000000;

int n, adj[16][16];
int cache[1<<16][16];
int ALL;

int tsp(int u, unsigned int visit)
{
  if(visit == ALL) return adj[u][0];
  int& ret = cache[visit][u];
  if(ret != -1) return ret;
  ret = MX_INT;
  for(int v=0; v<n; ++v) {
    if(visit&(1<<v)) continue;
    visit |= (1<<v);
    ret = min(ret, adj[u][v] + tsp(v,visit));
    visit ^= (1<<v);
  }
  return ret;
}

int main()
{
  scanf("%d",&n);
  ALL = (1<<n)-1;
  int ipt;
  for(int y=0; y<n; ++y)
    for(int x=0; x<n; ++x) {
      scanf("%d",&ipt);
      adj[y][x] = (ipt==0) ? MX_INT : ipt;
    }
  memset(cache,-1,sizeof cache);
  printf("%d",tsp(0,1));
}
