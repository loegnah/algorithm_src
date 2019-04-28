#include <cstdio>
using namespace std;

int main()
{
  int t,tc=1;
  for(scanf("%d",&t); tc<=t; ++tc) {
    int ans = 0,n,k,ccy[2][16]={0},ccx[2][16]={0},ipt;
    scanf("%d %d",&n,&k);
    for(int y=1; y<=n; ++y) {
      int h = y%2;
      for(int x=1; x<=n; ++x) {
        scanf("%d",&ipt);
        if(ipt) {
          ccy[h][x] = ccy[1-h][x] + 1;
          if(ccy[h][x]==k) ++ans;
          else if(ccy[h][x]==k+1) --ans;
          ccx[h][x] = ccx[h][x-1] + 1;
          if(ccx[h][x]==k) ++ans;
          else if(ccx[h][x]==k+1) --ans;
        }
        else
          ccy[h][x] = ccx[h][x] = 0;
      }
    }
    printf("#%d %d\n",tc,ans);
  }
}
