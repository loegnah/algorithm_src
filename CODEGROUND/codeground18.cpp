/* 마라톤 경로 */
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int MX = 987654321;
int n,m,k;
int high[103][103];
int cache[102][102][12];

int absh(int h1,int h2)
{
  return abs(abs(h1)-abs(h2));
}

int dp(int y,int x,int water)
{
  if(high[y][x]<0 && water<k) water++;
  if(y==n && x==m) return (water>=k ? 0:MX);

  int& ret = cache[y][x][water];
  if(ret != -1) return ret;
  ret = MX;
  if(y<n) ret = dp(y+1,x,water) + absh(high[y][x],high[y+1][x]);
  if(x<m) ret = min(ret,dp(y,x+1,water) + absh(high[y][x],high[y][x+1]));
  return ret;
}

int main(int argc, char** argv)
{
  setbuf(stdout,NULL);
  int t,ipt;
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    memset(cache,-1,sizeof cache);
    scanf("%d %d %d",&m,&n,&k);
    for(int y=0; y<=n; ++y)
      for(int x=0; x<=m; ++x)
        scanf("%d",&high[y][x]);
    int ans = dp(0,0,0);
    printf("Case #%d\n",tc);
    printf("%d\n",ans);

  }
}
