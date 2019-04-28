#include <cstdio>
using namespace std;

const int MX_NODE = 1000;

int n,childNum[MX_NODE+3][2];
char tree[MX_NODE+3][20];

int make_num(char s[])
{
    int ret = s[0]-'0';
    for(int idx=1; s[idx]; ++idx) ret = ret*10 + (s[idx]-'0');
    return ret;
}

int search_calc(int cur)
{
    if(tree[cur][0]>='0') return make_num(tree[cur]);

    int opr = tree[cur][0], lc = childNum[cur][0], rc = childNum[cur][1];
    if(opr=='+') return search_calc(lc) + search_calc(rc);
    if(opr=='-') return search_calc(lc) - search_calc(rc);
    if(opr=='*') return search_calc(lc) * search_calc(rc);
    if(opr=='/') return search_calc(lc) / search_calc(rc);
}

int main()
{
    int k,j;
    char s[20];
    for(int tc=1; tc<=10; ++tc) {
        scanf("%d",&n);
        for(int i=1; i<=n; ++i) {
            scanf("%d %s",&k,&s);
            for(j=0; s[j]; ++j) tree[k][j] = s[j];
            tree[k][j] = '\0';
            if(s[0]<'0') scanf("%d %d",&childNum[k][0],&childNum[k][1]);
        }
        printf("#%d %d\n",tc,search_calc(1));
    }
}
