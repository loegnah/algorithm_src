#include <cstdio>
#include <cstring>
using namespace std;

const char W = 'W';
const char B = 'B';

char board[1001][1001];
int row[1001], col[1001];

int main()
{
    int T,N,ans,cnt;
    scanf("%d",&T);
    for(int tc=1; tc<=T; ++tc) {
        //input
        scanf("%d",&N);
        for(int i=0; i<N; ++i) scanf("%s",board[i]);

        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));

        //solve

        for(int y=0; y<N; ++y) for(int x=0; x<N; ++x) {
            if(board[y][x] == B) {
                ++row[y];
                ++col[x];
            }
        }

        ans = 0;
        for(int y=0; y<N; ++y) for(int x=0; x<N; ++x) {
            cnt = (board[y][x] == B) ? -1 : 0;
            cnt += row[y]+col[x];
            if(cnt % 2) ++ans;
        }

        printf("#%d %d\n",tc,ans);
    }
}