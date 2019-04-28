#include <cstdio>
using namespace std;

const char ZR = '0';

int main()
{
    int n,k,lc,rc;
    char a;
    setbuf(stdout,NULL);

    for(int tc=1; tc<=10; ++tc) {
        scanf("%d",&n);

        int ans = 1;
        for(int i=1; i<=n; ++i) {
            scanf("%d %c",&k,&a);

            lc = rc = -1;
            if(k+k<=n) scanf("%d",&lc);
            if(k+k+1<=n) scanf("%d",&rc);

            if(a>=ZR && lc!=-1) ans = 0;
            if(a<ZR && rc==-1) ans = 0;
        }
        printf("#%d %d\n",tc,ans);
    }
}
