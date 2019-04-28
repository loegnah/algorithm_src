#include <cstdio>
using namespace std;

const int L = 100;
const int cy[4] = {0,1,0,-1}, cx[4] = {1,0,-1,0};

int bgy,bgx,enx,eny;
char board[L+1][L+1];
bool isVisit[L][L];

void dfs(int y, int x)
{
    isVisit[y][x] = true;

    for(int i=0; i<4; ++i) {
        int ny = y+cy[i], nx = x+cx[i];
        if(board[ny][nx]!='1' && !isVisit[ny][nx]) dfs(ny,nx);
    }
}

int main()
{
    int tmp;
    for(int tc=1; tc<=10; ++tc) {
        scanf("%d",&tmp);
        for(int y=0; y<L; ++y) {
            scanf("%s",&board[y][0]);
            for(int x=0; x<L; ++x) {
                if(board[y][x]=='2') {bgy=y; bgx=x;}
                else if(board[y][x]=='3') {eny=y; enx=x;}
                isVisit[y][x] = false;
            }
        }
        dfs(bgy,bgx);
        int ans = (isVisit[eny][enx] ? 1 : 0);
        printf("#%d %d\n",tc,ans);
    }
}
