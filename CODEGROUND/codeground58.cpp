#include <cstdio>
using namespace std;

int main()
{
  int t;
  setbuf(stdout,NULL);
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    int n, ipt, pre = 1000000005, ans = 0;
    bool pre_buy = false;
    scanf("%d",&n);
    for(int i=0; i<n; ++i) {
      scanf("%d",&ipt);
      if(ipt<pre) {
        if(!pre_buy) {
          ans++;
          pre_buy = true;
        }
        pre = ipt;

      }
      else if(ipt>pre) {
        if(pre_buy) {
          ans++;
          pre_buy = false;
        }
        pre = ipt;
      }
    }
    printf("Case #%d\n%d\n",tc,(ans/2)*2);
  }
}
