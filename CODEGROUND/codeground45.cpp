/*
  약간 역발상으로 푸는 문제다..
  만들 수 있는 점수의 집합을 만들어서 푼다. */

#include <cstdio>
#include <cstring>
using namespace std;

int t,n,m,sc,mx;
bool canMake[10002];

int main()
{
  setbuf(stdout,NULL);
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    memset(canMake,0,sizeof canMake);
    canMake[0] = true;
    mx = 0;

    scanf("%d %d",&n,&m);
    for(int k=0; k<n; ++k) {
      scanf("%d",&sc);
      for(int i=0; i<=mx; ++i) {
        if(canMake[i] && (i+sc<=m)) canMake[i+sc] = true;
        if(mx+sc <= m) mx += sc;
      }
    }
    for(int a=m; a>=0; --a) {
      if(canMake[a]) {
        printf("Case #%d\n%d\n",tc,a);
        break;
      }
    }
  }
  return 0;
}
