#include <cstdio>
using namespace std;

const int MX_N = 1000+5;
const int MX = MX_N*MX_N;
const int NONO = -200;
const int cy[4] = {0,1,0,-1};
const int cx[4] = {1,0,-1,0};

int n,A[MX_N][MX_N], cache[MX_N][MX_N];
int start, mxMove;

int _max(int a,int b) {return a>b? a:b;}

void input()
{
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) {
        scanf("%d",&A[i][j]);
        cache[i][j] = -1;
    }
    for(int i=1; i<=n; ++i)
        A[0][i] = A[n+1][i] = A[i][0] = A[i][n+1] = -200;
}

int dfs(int y, int x)
{
    int& ret = cache[y][x];
    if(ret != -1) return ret;
    ret = 1;

    for(int i=0; i<4; ++i)
        if(A[y][x]+1 == A[y+cy[i]][x+cx[i]]) {
            ret += dfs(y+cy[i],x+cx[i]);
            break;
        }
    return ret;
}

void solve()
{
    int move;
    start = MX;
    mxMove = 0;

    for(int y=1; y<=n; ++y) for(int x=1; x<=n; ++x) {
        if(cache[y][x] == -1) move = dfs(y,x);
        if(mxMove<move) {start = A[y][x]; mxMove = move;}
        else if(mxMove==move && A[y][x]<start) start = A[y][x];
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int tc=1; tc<=t; ++tc) {
        input();
        solve();

        printf("#%d %d %d\n",tc,start,mxMove);
    }
}
