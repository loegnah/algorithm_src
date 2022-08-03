#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[100005];
int prnt[100005] = {0};

void dfs(int cur)
{
    for(int nxt : adj[cur]) {
        if(prnt[nxt]) continue;
        prnt[nxt] = cur;
        dfs(nxt);
    }
}

int main()
{
    int N, a, b;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for(int i=0; i<N-1; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);
    for(int i=2; i<=N; ++i) cout << prnt[i] << '\n';
}