#include <cstdio>
using namespace std;

int main()
{
  int t,tc,n,m,pr[16][16]={0,},tmp;
  for(scanf("%d",&t),tc=1; tc<=t; ++tc) {
    scanf("%d %d",&n,&m);

    for(int i=1; i<=n; ++i) {
      scanf("%d",&pr[i][1]);
      for(int j=2; j<=n; ++j) {
        scanf("%d",&tmp);
        pr[i][j] = tmp + pr[i][j-1];
      }
    }

    long long mx = 0;
    for(int y=m; y<=n; ++y) {
      for(int x=m; x<=n; ++x) {
        long long tot = 0;
        for(int k=y-m+1; k<=y; ++k) tot += pr[k][x]-pr[k][x-m];
        if(mx<tot) mx = tot;
      }
    }
    printf("#%d %d\n",tc,mx);
  }
}
