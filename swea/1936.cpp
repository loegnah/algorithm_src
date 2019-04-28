#include <cstdio>
using namespace std;

int main()
{
  int a,b,ans;
  char ch[3] = "AB";
  scanf("%d %d",&a,&b);
  if(a==1) ans = (b==3) ? 0 : 1;
  else ans = (a>b) ? 0 : 1;
  printf("%c",ch[ans]);
}
