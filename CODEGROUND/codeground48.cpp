#include <cstdio>
using namespace std;

int main(int argc, char** argv)
{
  int t,a,b,d,ans;
  setbuf(stdout,NULL);
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    scanf("%d %d %d",&a,&b,&d);
    if(d-a<=0) ans = 1;
    else ans = 1+(d-b-1)/(a-b);
    printf("Case #%d\n%d\n",tc,ans);
  }
  return 0;
}
