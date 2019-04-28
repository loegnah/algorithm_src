#include <cstdio>
using namespace std;

int dump,h[105],mx,mxIdx,mn,mnIdx,tmph;

void calcDif()
{
  mx = -1; mn = 999;
  for(int i=0; i<100; ++i) {
    tmph = h[i];
    if(tmph<mn) { mn = tmph; mnIdx = i; }
    if(tmph>mx) { mx = tmph; mxIdx = i; }
  }
}

int main()
{
  for(int tc=1; tc<=10; ++tc) {
    scanf("%d",&dump);
    for(int i=0; i<100; ++i) scanf("%d",h+i);

    while(dump--) {
      calcDif();
      if(mxIdx == mnIdx) break;
      h[mxIdx]--;
      h[mnIdx]++;
    }
    calcDif();

    printf("#%d %d\n",tc,mx-mn);
  }
}
