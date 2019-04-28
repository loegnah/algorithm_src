#include <cstdio>
using namespace std;

int main()
{
  int t;
  long long n,sum;
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    scanf("%lld",&n);
    while(n>=10) {
      sum = 0;
      while(n) {
        sum += n%10;
        n /= 10;
      }
      n = sum;
    }
    printf("#%d %lld\n",tc,n);
  }
}
