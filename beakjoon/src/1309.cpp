#include <cstdio>
#include <cstring>
using namespace std;

const int MOD = 9901;
int cache[100002][2];
int N;

int dp(int n, int pre)
{
  if(n==N) return 1;
  if(pre == -1) return (dp(n+1,1)*2)%MOD;

  int& ret = cache[n][pre];
  if(ret != -1) return ret;
  if(pre == 0)
    return ret = (dp(n+1,0)+2*dp(n+1,1))%MOD;
  else
    return ret = (dp(n+1,0)+dp(n+1,1))%MOD;
}

int main()
{
  memset(cache,-1,sizeof cache);
  scanf("%d",&N);
  int ans = 0;
  for(int i=0; i<N; ++i)
    ans = (ans+dp(i,-1))%MOD;
  printf("%d",ans+1);
}
