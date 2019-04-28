#include <cstdio>
using namespace std;

const int MXSIZE = 305;
const int cy[8] = {-1,-1,-1,0,1,1,1,0};
const int cx[8] = {-1,0,1,1,1,0,-1,-1};

char board[MXSIZE][MXSIZE];
int n, ans, state[MXSIZE][MXSIZE];

void input()
{
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) scanf("%s",&board[i][1]);
    for(int i=0; i<=n+1; ++i) {
        board[0][i] = board[n+1][i] = board[i][0] = board[i][n+1] = '#';
        state[0][i] = state[n+1][i] = state[i][0] = state[i][n+1] = 2;
    }
}

void checking()
{
    for(int y=1; y<=n; ++y) for(int x=1;x<=n; ++x) {
        if(board[y][x] == '*') {
            state[y][x] = 2;
            continue;
        }

        state[y][x] = 0;
        for(int i=0; i<8; ++i)
            if(board[y+cy[i]][x+cx[i]] == '*') {
                state[y][x] = 1;
                break;
            }
    }
}

void dfs(int y, int x)
{
    state[y][x] = 2;
    for(int i=0; i<8; ++i) {
        int ny = y+cy[i], nx = x+cx[i];
        if(state[ny][nx]==1) state[ny][nx] = 2;
        else if(state[ny][nx]==0) dfs(ny,nx);
    }
}

void solve()
{
    ans = 0;
    for(int y=1; y<=n; ++y) for(int x=1; x<=n; ++x) {
        if(state[y][x]==1) {
            ans++;
            for(int i=0; i<8; ++i)
                if(state[y+cy[i]][x+cx[i]] == 0) dfs(y+cy[i],x+cx[i]);
            else state[y][x]=2;
        }
        else if(state[y][x]==0) {
            ans++;
            dfs(y,x);
        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int tc=1; tc<=t; ++tc) {
        input();
        checking();
        solve();
        printf("#%d %d\n",tc, ans);
    }
}
