#include <cstdio>
#include <cstring>
using namespace std;

long long cache[101];

long long dp(int cur)
{
  if(cur <= 3) return 1;
  long long& ret = cache[cur];
  if(ret != -1LL) return ret;
  return ret = dp(cur-2)+dp(cur-3);
}

int main()
{
  int t,n;
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    scanf("%d",&n);
    memset(cache,-1LL,sizeof cache);
    printf("#%d %lld\n",tc,dp(n));
  }
}
