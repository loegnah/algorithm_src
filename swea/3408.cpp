#include <cstdio>
using namespace std;

int main()
{
  int t;
  long long n;
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    scanf("%lld",&n);
    long long ans = (n*(n+1LL))/2LL;
    printf("#%d %lld %lld %lld\n",tc,ans,ans*2LL-n,ans*2LL);
  }
}
