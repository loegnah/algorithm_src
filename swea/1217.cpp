#include <cstdio>
using namespace std;

int main()
{
  int t,a,b,ans;
  for(int tc=1; tc<=10; ++tc) {
    scanf("%d",&t);
    scanf("%d %d",&a,&b);
    for(ans=1; b>0; --b) ans *= a;
    printf("#%d %d\n",tc,ans);
  }
}
