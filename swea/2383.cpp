#include <cstdio>
#include <queue>
#include <cmath>
using namespace std;

struct Loc {
  int y,x;
  Loc() : y(0), x(0) {}
  Loc(int _y, int _x) : y(_y), x(_x) {}
};

int T,N,prsn,sn,height[2],dst[12],stan[12],goingDown[2][3];
Loc prs[12],sta[2];

int main()
{
  int tmp,p,a,b;
  scanf("%d",&T);
  for(int TC=1; TC<=T; ++TC)
  {
    prsn = 0;
    sn = 0;

    scanf("%d",&N);
    for(int y=0; y<N; ++y)
    {
      for(int x=0; x<N; ++x)
      {
        scanf("%d",&tmp);
        if(tmp==1) prs[prsn++] = Loc(y,x);
        else if(tmp>1)
        {
          sta[sn] = Loc(y,x);
          height[sn++] = tmp;
        }
      }
    }

    int mnTime = 987654321;
    for(int cs=0; cs < (1<<prsn); ++cs)
    {
      int waitn[2] = {0,0}, down[2][3] = {{0,0,0},{0,0,0}}, downNum[2]={0,0};
      int _time=1, complete = 0;

      for(p=0; p<prsn; ++p)
      {
        stan[p] = (cs>>p)&1;
        dst[p] = abs(prs[p].y-sta[stan[p]].y)
        + abs(prs[p].x-sta[stan[p]].x);
      }

      while(true)
      {
        for(a=0; a<2; ++a)
        {
          for(b=0; b<3; ++b)
          {
            if(down[a][b])
            {
              down[a][b]--;
              if(!down[a][b]) complete++;
            }
            if(waitn[a] && !down[a][b])
            {
              waitn[a]--;
              down[a][b] = height[a];
            }
          }
        }

        if(complete==prsn) break;

        for(p=0; p<prsn; ++p)
        {
          if(dst[p]==0) continue;
          if(dst[p]==1)
          {
            if(waitn[stan[p]]<3)
            {
                waitn[stan[p]]++;
                dst[p]--;
            }
          }
          else dst[p]--;
        }
        _time++;
      }
      if(mnTime>_time) mnTime = _time;
    }
    printf("#%d %d\n",TC,mnTime);
  }
}
