#include <cstdio>
using namespace std;

#define MM 8
const int don[MM] = {50000,10000,5000,1000,500,100,50,10};

int main()
{
  int t,k;
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    scanf("%d",&k);
    printf("#%d\n",tc);
    for(int i=0; i<MM; ++i) {
      printf("%d ",k/don[i]);
      k %= don[i];
    }
    printf("\n");
  }
}
