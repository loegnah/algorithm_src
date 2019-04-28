#include <cstdio>
using namespace std;

int main()
{
  int T,tc,n,ans;
  for(scanf("%d",&T),tc=1; tc<=T; ++tc) {
    scanf("%d",&n);
    ans = (n+1)/2;
    if(n%2==0) ans *= -1;
    printf("#%d %d\n",tc,ans);
  }
}
