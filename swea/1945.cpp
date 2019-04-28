#include <cstdio>
using namespace std;

const int arr[5] = {2,3,5,7,11};

int main()
{
  int t,n;
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    scanf("%d",&n);
    printf("#%d ",tc);
    for(int i=0; i<5; ++i) {
      int k = 0;
      while(n%arr[i]==0) {
        k++;
        n /= arr[i];
      }
      printf("%d ",k);
    }
    printf("\n");
  }
}
