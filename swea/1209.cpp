#include <cstdio>
#include <cstring>
using namespace std;

int hSum[100], vSum[100], dSum[2];

int main()
{
  int t,num;
  for(int tc=1; tc<=10; ++tc) {
    int mx = -1;
    memset(hSum,0,sizeof hSum);
    memset(vSum,0,sizeof vSum);
    dSum[0] = dSum[1] = 0;

    scanf("%d",&t);
    for(int i=0; i<100; ++i) {
      for(int j=0; j<100; ++j) {
        scanf("%d",&num);
        hSum[i] += num;
        vSum[j] += num;
        if(i==j) dSum[0] += num;
        if(i==99-j) dSum[1] += num;
      }
    }

    for(int i=0; i<100; ++i) if(mx < hSum[i]) mx = hSum[i];
    for(int i=0; i<100; ++i) if(mx < vSum[i]) mx = vSum[i];
    for(int i=0; i<2; ++i) if(mx < dSum[i]) mx = dSum[i];

    printf("#%d %d\n",tc,mx);
  }
}
