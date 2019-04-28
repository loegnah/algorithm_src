#include <cstdio>
#include <cstring>
using namespace std;

int dp[2][1001];


int main()
{
  int t,n,k,p;
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    scanf("%d %d",&n,&k);
    memset(dp,0,sizeof dp);
    dp[0][0] = dp[1][0] = 1;
    for(int i=0; i<n; ++i) {
      int h = i%2;
      scanf("%d",&p);
      for(int j=0; j<=k; ++j) dp[h][j] = dp[1-h][j];
      for(int j=0; j<=k-p; ++j) {
        if(dp[1-h][j]) dp[h][j+p] += dp[1-h][j];
      }
    }

    printf("#%d %d\n",tc,dp[1-n%2][k]);
  }
}
