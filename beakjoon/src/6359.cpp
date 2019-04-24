#include <cstdio>
#include <bitset>
using namespace std;

int main()
{
  int T,n;
  bitset<101> bs;
  scanf("%d",&T);
  while(T--) {
    scanf("%d",&n);
    bs.reset();
    for(int i=1; i<=n; ++i) {
      for(int j=i-1; j<n; j+=i)
        bs.flip(j);
    }
    printf("%d\n",bs.count());
  }
}
