#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
  int t;
  long long n,a,b;
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    scanf("%lld %lld %lld",&n,&a,&b);

    long long ans = 987654321 ;
    for(long long r=1; r<=n; ++r)
      for(long long c=1; r*c<=n; ++c)
          ans = min(ans,a*abs(r-c)+b*(n-r*c));
    printf("#%d %lld\n",tc,ans);
  }
}
