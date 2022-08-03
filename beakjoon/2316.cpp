#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int MX_NODE = 805;

struct Edge {
    int to, cp, fl;
    Edge *rev;
    Edge() : Edge(-1,0) {}
    Edge(int _to, int _cp) : to(_to), cp(_cp), fl(0), rev(nullptr) {}

    int remain() { return cp-fl; }
    void addFlow(int f) {
        fl += f;
        rev->fl -= f;
    }
};

vector<Edge*> adj[MX_NODE];
int fl[MX_NODE][MX_NODE] = {0};
int cp[MX_NODE][MX_NODE] = {0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, P, a, b;

    cin >> N >> P;
    while(P--) {
        cin >> a >> b;
        a = (a-1)*2;
        b = (b-1)*2;
        Edge *e1 = new Edge(b,1), *e2 = new Edge(a,1);
        e1->rev = e2;
        e2->rev = e1;
        adj[a+1].push_back(e1);
        adj[b+1].push_back(e2);
    }

    for(int i=0; i<N; ++i) {
        int ii = i*2;
        Edge *e1 = new Edge(ii+1,1), *e2 = new Edge(ii,0);
        e1->rev = e2;
        e2->rev = e1;
        adj[ii].push_back(e1);
        adj[ii+1].push_back(e2);
    }

    int st = 1, en = 2, pathCnt = 0;
    while(true) {
        queue<int> q;
        Edge *path[MX_NODE] = {nullptr};
        int pre[MX_NODE];
        fill(pre, pre+MX_NODE, -1);

        q.push(st);
        while(!q.empty() && pre[en]==-1) {
            int cur = q.front();
            q.pop();

            for(Edge *e : adj[cur]) {
                int nxt = e->to;
                if(e->remain()>0 && pre[nxt]==-1) {
                    q.push(nxt);
                    pre[nxt] = cur;
                    path[nxt] = e;
                    if(nxt == en) break;
                }
            }
        }

        if(pre[en] == -1) break;

        for(int i=en; i!=st; i=pre[i]) {
            path[i]->addFlow(1);
        }
        pathCnt++;
    }
    cout << pathCnt << '\n';
}