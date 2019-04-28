#include <cstdio>
using namespace std;

int main(int argc, char** argv)
{
  int t,n,m,k,ipt;
  int order[21];

  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1; i<=m; ++i) order[i] = 0;
    for(int i=0; i<n; ++i) {
      scanf("%d",&ipt);
      order[ipt]++;
    }

    int tot = 0;
    for(int i=1; i<=m; ++i) {
      scanf("%d",&ipt);
      tot += ipt*order[i];
    }
    
    printf("Case #%d\n",tc);
    if(tot<=k) printf("Y\n");
    else printf("N\n");
  }
  return 0;
}
