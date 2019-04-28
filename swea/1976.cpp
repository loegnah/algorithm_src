#include <cstdio>
using namespace std;

int main()
{
  int a,b,c,d,t;
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    scanf("%d %d %d %d",&a,&b,&c,&d);
    int h = (a+c+(b+d)/60)%12;
    if(h==0) h = 12;
    int m = (b+d)%60;
    printf("#%d %d %d\n",tc,h,m);
  }
}
