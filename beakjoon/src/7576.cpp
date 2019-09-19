#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int CY[4] = {0,1,0,-1};
const int CX[4] = {1,0,-1,0};

struct Loc {
    int x, y, t;

    Loc(): x(0), y(0), t(0) {}
    Loc(int _x, int _y, int _t): x(_x), y(_y), t(_t) {}
};

int M, N, total_tomato, ripe_tomato;
int state[1005][1005];
queue<Loc*> qu;

void input_init()
{
    int stt;

    cin >> M >> N;
    total_tomato = M*N;
    ripe_tomato = 0;
    for(int y=1; y<=N; ++y) 
        for(int x=1; x<=M; ++x) {
            cin >> stt;
            state[y][x] = stt;

            if(stt == 1) {
                qu.push(new Loc(x,y,0));
                ++ripe_tomato;
            }
            else if(stt < 0) 
                --total_tomato;
        }

    for(int x=0; x<=M+1; ++x) state[0][x] = state[N+1][x] = -1;
    for(int y=0; y<=N+1; ++y) state[y][0] = state[y][M+1] = -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input_init();

    int date = 0;
    while(!qu.empty()) {
        Loc *loc = qu.front();
        qu.pop();

        int y = loc->y, x = loc->x;
        date = loc->t;

        for(int i=0; i<4; ++i) {
            int ny = y+CY[i], nx = x+CX[i];
            if(state[ny][nx]) {
                continue;
            }
            ++ripe_tomato;
            qu.push(new Loc(nx, ny, date+1));
            state[ny][nx] = 1;
        }
    }
    
    if(ripe_tomato < total_tomato) cout << -1 << '\n';
    else cout << date << '\n';
}