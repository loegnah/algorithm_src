#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N,tri[502][502];
int cache[502][502];

int dp(int y, int x)
{
  if(y==N) return 0;
  int& ret = cache[y][x];
  if(ret != -1) return ret;
  return ret = tri[y][x] + max(dp(y+1,x), dp(y+1,x+1));
}

int main()
{
  memset(cache, -1, sizeof cache);
  scanf("%d",&N);
  for(int i=0; i<N; ++i) for(int j=0; j<=i; ++j)
    scanf("%d",&tri[i][j]);
  printf("%d",dp(0,0));
}
