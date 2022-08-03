#include <cstdio>
using namespace std;

int main()
{
  int N, a, ans = 0;
  bool ck;
  scanf("%d",&N);
  while(N--) {
    ck = true;
    scanf("%d",&a);
    if(a==1) continue;
    for(int i=2; i*i<=a; ++i) {
      if(a%i==0) {
        ck = false;
        break;
      }
    }
    if(ck) ans++;
  }
  printf("%d",ans);
}
