#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> adj[505];
bool visited[505];
int nodeCnt, edgeCnt;

void dfs(int cur)
{
    visited[cur] = true;
    ++nodeCnt;

    for(int nxt : adj[cur]) {
        ++edgeCnt;
        if(!visited[nxt]) {
            dfs(nxt);
        }
    }
}

int main()
{
    int n, m, a, b;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int tc=1; ; ++tc) {
        cin >> n >> m;
        if(n == 0 && m == 0) break;

        for(int i=1; i<=n; ++i) adj[i].clear();

        for(int i=0; i<m; ++i) {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        memset(visited, 0, sizeof(visited));

        int treeCnt = 0;
        for(int i=1; i<=n; ++i) {
            if(visited[i]) continue;

            nodeCnt = edgeCnt = 0;
            dfs(i);

            if(edgeCnt%2==0 && nodeCnt == edgeCnt/2+1)
                ++treeCnt;
        }
        cout << "Case " << tc << ": ";
        if(treeCnt > 2) cout << "A forest of " << treeCnt <<  " trees.";
        else if(treeCnt == 1) cout << "There is one tree.";
        else cout << "No trees.";
        cout << '\n';
    }
}