#include <cstdio>
using namespace std;

int main()
{
  int n,a,ans=0;
  scanf("%d",&n);
  for(int i=0; i<n; ++i) {
    scanf("%d",&a);
    if(a) ans++;
  }
  if(ans>n/2) printf("Junhee is cute!");
  else printf("Junhee is not cute!");
}
