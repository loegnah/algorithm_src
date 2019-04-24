#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

const char ZR = '0';

int N,M,a,b;
vector<vector<int>> adj;
vector<int> inDegree;
priority_queue<int> pq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;

    adj.resize(N+1);
    inDegree = vector<int>(N+1,0);
    pq = priority_queue<int>();

    for(int i=0; i<M; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        ++inDegree[b];
    }

    for(int i=1; i<=N; ++i) {
        if(!inDegree[i]) pq.push(-i);
    }

    string ans = "";
    while(!pq.empty()) {
        int cur = -pq.top(); pq.pop();
        ans += to_string(cur) + ' ';
        for(int nxt : adj[cur]) {
            --inDegree[nxt];
            if(!inDegree[nxt]) pq.push(-nxt);
        }
    }

    cout << ans << "\n";
}