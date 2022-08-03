#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int MX_N = 401;

vector<int> adj[MX_N];
int fl[MX_N][MX_N] = {0};
int cp[MX_N][MX_N] = {0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, P, a, b;

    cin >> N >> P;
    while(P--) {
        cin >> a >> b;
        cp[a][b] += 1;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int st = 1, en = 2, pathCnt = 0;
    while(true) {
        queue<int> q;
        int pre[MX_N];
        fill(pre, pre+MX_N, -1);
        
        q.push(st);
        while(!q.empty() && pre[en]==-1) {
            int cur = q.front();
            q.pop();

            for(int nxt : adj[cur]) {
                if(cp[cur][nxt]-fl[cur][nxt]>0 && pre[nxt]==-1) {
                    q.push(nxt);
                    pre[nxt] = cur;
                    if(nxt == en) break;
                }
            }
        }

        if(pre[en] == -1) break;

        for(int i=en; i!=st; i=pre[i]) {
            fl[pre[i]][i] += 1;
            fl[i][pre[i]] -= 1;
        }
        
        pathCnt++;
    }
    cout << pathCnt << '\n';
}