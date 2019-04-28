#include <cstdio>
using namespace std;

int main()
{
  int t;
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    int mx = -1, ipt;
    for(int i=0; i<10; ++i) {
      scanf("%d",&ipt);
      if(mx<ipt) mx = ipt;
    }
    printf("#%d %d\n",tc,mx);
  }
}
