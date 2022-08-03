#include <cstdio>
using namespace std;

int facto[41] = {1,1,2,3};

void calc_facto(int n)
{
  for(int i=4; i<=n; ++i)
    facto[i] = facto[i-1] + facto[i-2];
}

int main()
{
  int n,m;
  int vip[41];
  scanf("%d",&n);
  scanf("%d",&m);
  for(int i=0; i<m; ++i)
    scanf("%d",vip+i);
  calc_facto(n);
  if(m==0) {
    printf("%d",facto[n]);
  }
  else {
    int len = vip[0]-1;
    int ans = facto[len];
    vip[m] = n+1;
    for(int i=1; i<=m; ++i) {
      len = vip[i] - vip[i-1] -1;
      if(len>0) ans *= facto[len];
    }
    printf("%d",ans);
  }
}
