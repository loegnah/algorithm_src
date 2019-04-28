#include <cstdio>
using namespace std;

int main()
{
  int t,p,q,r,s,w,a,b;
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    scanf("%d %d %d %d %d",&p,&q,&r,&s,&w);
    a = w*p;
    b = (w<=r) ? q : q+s*(w-r);
    printf("#%d %d\n",tc,(a<b)?a:b);
  }
}
