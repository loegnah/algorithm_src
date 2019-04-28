#include <cstdio>
using namespace std;

int main()
{
  int t;
  long long a,b;
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    scanf("%lld %lld",&a,&b);
    printf("#%d %lld\n",tc,(a/b)*(a/b));
  }
}
