#include <cstdio>
#include <cstring>
using namespace std;

int m,n;
int h[501][501];
int cy[4] = {-1,0,1,0} , cx[4] = {0,1,0,-1};
int cache[501][501];

int dp(int y,int x)
{
  if(y == m-1 && x == n-1) return 1;
  int& ret = cache[y][x];
  if(ret != -1) return ret;
  ret = 0;
  int curHi = h[y][x];
  for(int i=0; i<4; ++i) {
    int ny = y+cy[i], nx = x+cx[i];
    if(ny<0 || ny>=m || nx<0 || nx>=n || curHi<=h[ny][nx]) continue;
    ret += dp(ny,nx);
  }
  return ret;
}


int main()
{
  memset(cache,-1,sizeof cache);
  scanf("%d %d",&m,&n);
  for(int y=0; y<m; ++y)
    for(int x=0; x<n; ++x)
      scanf("%d",&h[y][x]);
  printf("%d",dp(0,0));
}
