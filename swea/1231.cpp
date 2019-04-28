#include <cstdio>
using namespace std;

const int MX_NODE = 100;

int n,len;
char tree[MX_NODE+3],ans[MX_NODE+3];

void searchTree(int cur)
{
    if(cur+cur<=n) searchTree(cur+cur);
    ans[len++] = tree[cur];
    if(cur+cur+1<=n) searchTree(cur+cur+1);
}

int main()
{
    int k,c,a,b;
    for(int tc=1; tc<=10; ++tc) {
        len = 0;

        scanf("%d",&n);
        for(int i=1; i<=n; ++i) {
            scanf("%d %c",&k,&c);
            tree[k] = c;
            if(k+k<=n) scanf("%d",&a);
            if(k+k+1<=n) scanf("%d",&b);
        }
        searchTree(1);
        ans[len] = '\0';
        printf("#%d %s\n",tc,ans);
    }
}
