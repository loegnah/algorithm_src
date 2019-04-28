#include <cstdio>
using namespace std;

int T,N,M,C,y1,x1,y2,x2,mxHoney,allcase;
int beehives[12][12];

void calc_mx_honey()
{
  int chHoney,mx1=0,mx2=0,tmp;
  for(int ch1=1; ch1<allcase; ++ch1)
  {
    chHoney = 0;
    tmp = 0;
    for(int i=0; i<M; ++i)
      if((ch1>>i)&1)
      {
        chHoney += beehives[y1][x1+i];
        tmp += beehives[y1][x1+i] * beehives[y1][x1+i];
      }
    if(chHoney>C) continue;
    if(mx1<tmp) mx1 = tmp;
  }
  for(int ch2=1; ch2<allcase; ++ch2)
  {
    chHoney = 0;
    tmp = 0;
    for(int i=0; i<M; ++i)
      if((ch2>>i)&1)
      {
        chHoney += beehives[y2][x2+i];
        tmp += beehives[y2][x2+i] * beehives[y2][x2+i];
      }
    if(chHoney>C) continue;
    if(mx2<tmp) mx2 = tmp;
  }
  if(mxHoney<mx1+mx2) mxHoney = mx1+mx2;
}

int main()
{

  scanf("%d",&T);
  for(int TC=1; TC<=T; ++TC)
  {
    scanf("%d %d %d",&N,&M,&C);
    for(int y=0; y<N; ++y) for(int x=0; x<N; ++x) {
      scanf("%d",&beehives[y][x]);
    }

    mxHoney = 0;
    allcase = 1<<M;
    for(y1=0; y1<N; ++y1)
      for(x1=0; x1<N-M+1; ++x1)
      {
        y2 = y1;
        for(x2=x1+M; x2<N-M+1; ++x2) calc_mx_honey();

        for(y2=y1+1; y2<N; ++y2)
          for(x2=0; x2<N-M+1; ++x2) calc_mx_honey();
      }
    printf("#%d %d\n",TC,mxHoney);
  }
}
