#include <cstdio>
using namespace std;

int main()
{
  int t,n,d;
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    scanf("%d",&n);

    int dmn = 100001, count = 0;
    for(int i=0; i<n; ++i) {
      scanf("%d",&d);
      if(d<0) d *= -1;
      if(d<dmn) {
        dmn = d;
        count = 1;
      }
      else if(d==dmn) count++;
    }
    printf("#%d %d %d\n",tc,dmn,count);
  }
}
