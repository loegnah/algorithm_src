#include <cstdio>
#include <cstring>
using namespace std;

int a,b,c,n,k;
char ans[10];

int main(int argc, char** argv)
{
  setbuf(stdout,NULL);
  int t;
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    memset(ans,0,sizeof ans);
    scanf("%d %d %d",&a,&b,&c);
    for(int i=0; i<c; ++i) {
      scanf("%d %d",&n,&k);
      bool ck = false;
      int ak = a*k, bk = b*k;
      int mod_min = bk+a;
      int mod_max = ak+b;
      if(n<a) ck = false;
      else if(a<n && n<ak) ck = true;
      else {
        for(int mod=mod_min; mod<=mod_max; ++mod) {
          for(int game=n-b; game<=n-1; ++game) {
            int rmn = game%mod;
            if(a<=rmn && rmn<=ak) {
              ck = true;
              break;
            }
          }
          if(ck) break;
        }
      }
      if(ck) ans[i] = 'a';
      else ans[i] = 'b';
    }
    printf("Case #%d\n",tc);
    printf("%s\n",ans);
  }
}
