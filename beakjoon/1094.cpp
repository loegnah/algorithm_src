#include <cstdio>
using namespace std;

int main()
{
  int n,ans=0;
  scanf("%d",&n);
  while(n) {
    ans += n%2;
    n /= 2;
  }
  printf("%d",ans);
}
