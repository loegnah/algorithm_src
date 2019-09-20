#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int MX_V = 52;
const int INF = 1e9+7;

int fl[MX_V][MX_V] = {0};
int cp[MX_V][MX_V] = {0};
vector<int> adj[MX_V];

inline int cToI(const char ch) {
    if(ch <= 'Z') return (int)(ch-'A');
    return (int)(ch-'a'+26);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, a, b, d;
    char chA, chB;

    cin >> N;
    while(N--) {
        cin >> chA >> chB >> d;
        a = cToI(chA);
        b = cToI(chB);
        cp[a][b] += d;
        cp[b][a] += d;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int totFlow = 0, st = cToI('A'), en = cToI('Z');
    while(true) {
        queue<int> qu;
        int prev[MX_V];

        memset(prev, -1, sizeof(prev));
        qu.push(st);
        
        while(!qu.empty() && prev[en] == -1) {
            int cur = qu.front();
            qu.pop();

            for(int nxt : adj[cur]) {
                if(prev[nxt] == -1 && cp[cur][nxt]-fl[cur][nxt] > 0) {
                    qu.push(nxt);
                    prev[nxt] = cur;
                    if(nxt == en) break;
                }
            }
        }

        if(prev[en] == -1) break;

        int canFlow = INF;
        for(int i=en; i!=st; i=prev[i])
            canFlow = min(canFlow, cp[prev[i]][i]-fl[prev[i]][i]);
        for(int i=en; i!=st; i=prev[i]) {
            fl[prev[i]][i] += canFlow;
            fl[i][prev[i]] -= canFlow;
        }
        totFlow += canFlow;
    }
    cout << totFlow << '\n';
}