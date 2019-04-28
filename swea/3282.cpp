#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[2][1003];

int main()
{
  int t,n,k,v,c;
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    scanf("%d %d",&n,&k);

    memset(dp,-1,sizeof dp);
    dp[0][0] = dp[1][0] = 0;

    for(int i=0; i<n; ++i) {
      scanf("%d %d",&v,&c);
      int cur = i%2, pre = 1-(i%2);
      for(int wt=0; wt<=k; ++wt) dp[cur][wt] = dp[pre][wt];
      for(int wt=0; wt<=k-v; ++wt) {
        if(dp[pre][wt] != -1) dp[cur][wt+v] = max(dp[cur][wt+v],dp[pre][wt]+c);
      }
    }
    int ans = 0;
    for(int i=0; i<=k; ++i) ans = max(ans,dp[1-n%2][i]);
    printf("#%d %d\n",tc,ans);
  }
}
