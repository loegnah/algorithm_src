#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <utility>
using namespace std;

const int MX_N = 300;
const int INF = 1e9+7;

int K, N, M;

int fl[MX_N][MX_N];
int cp[MX_N][MX_N];
int nodeCnt[MX_N][MX_N];
vector<int> adj[MX_N];
vector<pair<int,int>> satNode;

void input_init()
{
    int a, b, w;
    cin >> N >> M;

    memset(fl, 0, sizeof(fl));
    memset(cp, 0, sizeof(cp));
    memset(nodeCnt, 0, sizeof(nodeCnt));
    for(int i=0; i<N; ++i) adj[i].clear();
    satNode.clear();

    while(M--) {
        cin >> a >> b >> w;
        --a; --b;
        cp[a][b] += w;
        nodeCnt[a][b]++;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

bool flowCalc(int st, int en, bool findSat)
{
    while(true) {
        queue<int> qu;
        int pre[N];
        memset(pre, -1, sizeof(pre));

        qu.push(st);
        while(!qu.empty() && pre[en] == -1) {
            int cur = qu.front();
            qu.pop();

            for(int nxt : adj[cur]) {
                if(cp[cur][nxt]-fl[cur][nxt]>0 && pre[nxt]==-1) {
                    pre[nxt] = cur;
                    qu.push(nxt);
                    if(nxt == en) break;
                }
            }
        }

        if(pre[en] == -1) break;

        if(!findSat) return true;
        
        int canFlow = INF;
        for(int i=en; i!=st; i=pre[i])
            canFlow = min(canFlow, cp[pre[i]][i]-fl[pre[i]][i]);  
    
        for(int i=en; i!=st; i=pre[i]) {
            if(cp[pre[i]][i]-fl[pre[i]][i] == canFlow)
                satNode.push_back(pair<int,int>(pre[i],i));
            fl[pre[i]][i] += canFlow;
            fl[i][pre[i]] -= canFlow;
        }
    }
    return false;
}

int solve()
{
    int ans = 0;

    flowCalc(0, N-1, true);
    
    for(auto uv : satNode) {
        int u = uv.first, v = uv.second;
        cp[u][v]--;
        if(!flowCalc(u, v, false)) 
            ans += nodeCnt[u][v];
        cp[u][v]++;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> K;
    while(K--) {
        input_init();
        cout << solve() << '\n';
    }
}