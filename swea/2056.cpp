#include <cstdio>
using namespace std;

int main()
{
  int t,n;
  const int lastDay[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    scanf("%d",&n);
    int d = n%100, m = (n/100)%100, y = (n/10000);
    if(1<=m && m<=12 && 1<=d && d<=lastDay[m])
      printf("#%d %04d/%02d/%02d\n",tc,y,m,d);
    else printf("#%d %d\n",tc,-1);
  }
}
