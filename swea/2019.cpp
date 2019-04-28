#include <cstdio>
using namespace std;

int main()
{
  int n,k=1;
  scanf("%d",&n);
  ++n;
  while(n--) {
    printf("%d ",k);
    k <<= 1;
  }
}
