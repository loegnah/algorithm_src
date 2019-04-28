#include <cstdio>
#include <algorithm>
using namespace std;

const char* comm[2] = {"Impossible","Possible"};

int main()
{
  int t,n,m,k,ps[100];
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0; i<n; ++i) scanf("%d",ps+i);
    sort(ps,ps+n);

    int ck = 1;
    for(int i=0; i<n; ++i) {
      if(ps[i]/m*k < i+1) {ck = 0; break; }
    }

    printf("#%d %s\n",tc,comm[ck]);
  }
}
