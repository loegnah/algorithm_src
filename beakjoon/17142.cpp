#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;

const int MX_DIST = 999999;

class Point {
public:
    int y, x;
    Point(int _y, int _x): y(_y), x(_x) {}
};

int N, M;
int board[52][52];
int dist[52][52][11];
vector<Point*> virusLoc;

void calc_distance(int vIdx)
{
    int vy = virusLoc[vIdx]->y, vx = virusLoc[vIdx]->x;
    bool isVisited[N+1][N+1];

    dist[vy][vx] = 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dist, -1, sizeof(dist));

    cin >> N >> M;
    for(int y=1; y<=N; ++y) for(int x=1; x<=N; ++x) {
        cin >> board[y][x];
        if(board[y][x] == 2) virusLoc.push_back(new Point(y,x));
    }

    for(int i=0; i<virusLoc.size(); ++i) {
        
    }
}