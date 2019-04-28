#include <cstdio>
using namespace std;

int main()
{
  int t,num[8],k;
  for(int tc=1; tc<=10; ++tc) {
    scanf("%d",&t);
    for(int i=0; i<8; ++i) scanf("%d",num+i);

    k=0;
    while(true) {
      num[k%8] -= k%5+1;
      if(num[k%8]<=0) break;
      k++;
    }
    num[k%8] = 0;
    printf("#%d",tc);
    for(int i=1; i<=8; ++i) printf(" %d",num[(k+i)%8]);
    printf("\n");
  }
}
