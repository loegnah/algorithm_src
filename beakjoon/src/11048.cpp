#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m;
int candy[1002][1002];
int cache[1002][1002];

int dp(int y,int x)
{
  if(y==n || x==m) return 0;
  if(y==n-1 && x==m-1) return candy[y][x];
  int& ret = cache[y][x];
  if(ret != -1) return ret;
  return ret = candy[y][x] + max(dp(y+1,x), max(dp(y,x+1), dp(y+1,x+1)));
}

int main()
{
  memset(cache,-1,sizeof cache);
  scanf("%d %d",&n, &m);
  for(int i=0; i<n; ++i) for(int j=0; j<m; ++j)
    scanf("%d",&candy[i][j]);
  printf("%d",dp(0,0));
}
