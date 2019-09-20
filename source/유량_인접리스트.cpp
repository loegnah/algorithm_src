#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

const int MX_V = 52;
const int MX = 1e9+7;

struct Edge {
    int to, fl, cp;
    Edge* rev;
    
    Edge(): Edge(-1,0) {}
    Edge(int _to, int _cp): to(_to), cp(_cp), fl(0), rev(nullptr) {}
    int remain() { return cp-fl; }
    void addFlow(int f) {
        fl += f;
        rev->fl -= f;
    }
};

inline int cToI(const char ch) {
    if(ch <= 'Z') return (int)(ch - 'A');
    return (int)(ch - 'a' + 26);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<Edge*> adj[MX_V];
    char chA, chB;
    int N, d, a, b;

    cin >> N;
    for(int i=0; i<N; ++i) {
        cin >> chA >> chB >> d;
        a = cToI(chA);
        b = cToI(chB);
        
        Edge *e1 = new Edge(b, d);
        Edge *e2 = new Edge(a, 0);
        e1->rev = e2;
        e2->rev = e1;

        adj[a].push_back(e1);
        adj[b].push_back(e2);
    }

    int totFlow = 0, st = cToI('A'), en = cToI('Z');
    while(true) {
        Edge *path[MX_V] = {nullptr};
        int prev[MX_V];
        queue<int> qu;

        memset(prev, -1, sizeof(prev));
        qu.push(st);
        
        while(!qu.empty() && prev[en] == -1) {
            int cur = qu.front();
            qu.pop();

            for(Edge *edg : adj[cur]) {
                int nxt = edg->to;
                if(prev[nxt] == -1 && edg->remain()) {
                    prev[nxt] = cur;
                    path[nxt] = edg;
                    qu.push(nxt);
                    if(nxt == en) break;
                }
            }
        }

        if(prev[en] == -1) break;

        int canFlow = MX;
        for(int i=en; i!=st; i=prev[i])
            canFlow = min(canFlow, path[i]->remain());
        for(int i=en; i!=st; i=prev[i])
            path[i]->addFlow(canFlow);
        totFlow += canFlow;
    }
    cout << totFlow << '\n';
}