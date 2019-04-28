#include <cstdio>
using namespace std;

int main()
{
  int t,a,b,ans;
  char ch[4] = ">=<";
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    scanf("%d %d",&a,&b);
    ans = (a>b)?0:(a<b?2:1);
    printf("#%d %c\n",tc,ch[ans]);
  }
}
