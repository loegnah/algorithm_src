#include <cstdio>
using namespace std;

int main()
{
  int t;
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    int ans = 0, n;
    for(int i=0; i<10; ++i) {
      scanf("%d",&n);
      if(n&1) ans += n;
    }
    printf("#%d %d\n",tc,ans);
  }
}
