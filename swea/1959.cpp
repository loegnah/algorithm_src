#include <cstdio>
using namespace std;

const int MN = -2000000001;
int an[20],am[20];

int main()
{
  int t,n,m;
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    scanf("%d %d",&n,&m);
    for(int i=0; i<n; ++i) scanf("%d",an+i);
    for(int i=0; i<m; ++i) scanf("%d",am+i);

    int ans = MN, sum;
    if(n<=m) {
      for(int i=0; i<=m-n; ++i) {
        sum = 0;
        for(int j=0; j<n; ++j) sum += an[j]*am[i+j];
        if(sum > ans) ans = sum;
      }
    }
    else {
      for(int i=0; i<=n-m; ++i) {
        sum = 0;
        for(int j=0; j<m; ++j) sum += an[i+j]*am[j];
        if(sum > ans) ans = sum;
      }
    }
    printf("#%d %d\n",tc,ans);
  }
}
