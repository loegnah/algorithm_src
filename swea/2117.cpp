#include <cstdio>
#include <algorithm>
using namespace std;

struct Loc {
  int y,x;
};

int T,N,M,hCnt;
int dist[22][22][402], idx[22][22];
Loc home[405];

int _abs(int a) { return (a<0)?-a:a; }

int main()
{
  int tmp,mxInCnt,y,x,k,i,ans,mxTot;

  scanf("%d",&T);
  for(int TC=1; TC<=T; ++TC)
  {
    scanf("%d %d",&N,&M);

    mxTot = ans = hCnt = 0;

    //input
    for(y=0; y<N; ++y) for(x=0; x<N; ++x)
    {
      scanf("%d",&tmp);
      if(tmp) { home[hCnt].y = y; home[hCnt++].x = x; }
      idx[y][x] = 0;
    }

    //calc distance
    for(y=0; y<N; ++y) for(x=0; x<N; ++x)
    {
      for(i=0; i<hCnt; ++i)
        dist[y][x][i] = _abs(y-home[i].y) + _abs(x-home[i].x);

      sort(dist[y][x],dist[y][x]+hCnt);
    }

    for(k=1; k<=2*N; ++k)
    {
      int mxHome = -1;
      int cost = k*k+(k-1)*(k-1);

      for(y=0; y<N; ++y) for(x=0; x<N; ++x)
      {
        for(i=0; i<hCnt && dist[y][x][i]<k; ++i);
        if(mxHome<i) mxHome = i;
      }
      int tot = M*mxHome-cost;
      if(mxTot<tot) {mxTot = tot; ans = mxHome;}
    }
    printf("#%d %d\n",TC,ans);
  }
}
