/*
  징검다리
  완전 소스보고 따라한 코드... 어휴 */
#include <cstdio>
#include <cstring>
using namespace std;

const int MOD = 1000000009;
int t,n,k,l,tmp;
int tot_case[50002];
bool mine[50002];
int dp[50002][102];

int main(int argc, char** argv)
{
  setbuf(stdout,NULL);
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    scanf("%d %d %d",&n,&k,&l);
    memset(mine,0,sizeof mine);
    for(int i=0; i<l; ++i) {
      scanf("%d",&tmp);
      mine[tmp] = true;
    }
    memset(dp,0,sizeof dp);
    tot_case[0] = 1;
    dp[0][0] = 1;
    for(int i=1; i<=n; ++i) {
      tot_case[i] = 0;
      if(mine[i]) continue;
      for(int j=1; j<=k && i-j>=0; ++j) {
        dp[i][j] = ((tot_case[i-j]+MOD)-dp[i-j][j])%MOD;
        tot_case[i] = (tot_case[i] + dp[i][j])%MOD;
      }
    }
    printf("Case #%d\n%d\n",tc,tot_case[n]);
  }
}
