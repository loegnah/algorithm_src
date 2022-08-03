#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MX_N = 1000;
const int MX_M = 1000;

int N,M;
vector<int> adj[MX_N + MX_M];
bool isVisited[MX_N + MX_M];
int person[MX_N], work[MX_M];

bool dfs(int cur)
{
    int p = 0;
    isVisited[cur] = true;
    
    for(int wk : adj[cur]) {
        p = work[wk];
        if(p == -1 || !isVisited[p] && dfs(p)) {
            person[cur] = wk;
            work[wk] = cur;
            return true;
        }
    }
    return false;
}

int main()
{
    int wCnt, w, matched = 0;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for(int i=0; i<N; ++i) {
        cin >> wCnt;
        while(wCnt--) {
            cin >> w;
            adj[i].push_back(w-1);
        }
    }

    fill(person, person+N, -1);
    fill(work, work+M, -1);
    for(int i=0; i<N; ++i) {
        if(person[i] == -1) {
            fill(isVisited, isVisited+N, false);
            if(dfs(i)) ++matched;
        }
    }
    cout << matched << '\n';
}