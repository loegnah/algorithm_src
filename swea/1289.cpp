#include <cstdio>
using namespace std;

int main()
{
  int t;
  char ipt[55];
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    scanf("%s",ipt);

    int i=0, ans=0;
    while(ipt[i]) {
      if(ans%2 != ipt[i]%2) ++ans;
      ++i;
    }
    printf("#%d %d\n",tc,ans);
  }
}
