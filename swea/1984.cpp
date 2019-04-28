#include <cstdio>
using namespace std;

int main()
{
  int t,tc=1,ipt;
  for(scanf("%d",&t); tc<=t; ++tc) {
    int mx = -1, mn = 10001, ans = 0;
    for(int i=0; i<10; ++i) {
      scanf("%d",&ipt);
      ans += ipt;
      if(mx<ipt) mx = ipt;
      if(mn>ipt) mn = ipt;
    }
    ans -= mx+mn;
    printf("#%d %d\n",tc,(ans+4)/8);
  }
}
