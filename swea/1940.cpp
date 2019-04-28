#include <cstdio>
using namespace std;

int main()
{
  int t,n;
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    scanf("%d",&n);

    int d = 0, cmd, a, v=0;
    for(int i=0; i<n; ++i) {
      scanf("%d",&cmd);
      if(cmd) {
        scanf("%d",&a);
        v += (cmd==1) ? a:-a;
      }
      if(v<0) v = 0;
      d += v;
    }
    printf("#%d %d\n",tc,d);
  }
}
