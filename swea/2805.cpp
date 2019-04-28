#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
  int t,n,tmp;
  char ipt[50];
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    scanf("%d",&n);

    int ans = 0;
    for(int i=0, k=n/2; i<n; ++i,--k) {
      scanf("%s",ipt);
      for(int j=abs(k); j<n-abs(k); ++j) ans += ipt[j]-'0';
    }
    printf("#%d %d\n",tc,ans);
  }
}
