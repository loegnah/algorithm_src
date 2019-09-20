#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

const int MX_N = 1005;
const int INF = 987654321;

using PI = pair<int,int>;

int asdf;
int N, M;
bool isVisit[MX_N] = {false};
bool isChecked[MX_N] = {false};
int pre[MX_N] = {0};
int dist[MX_N] = {0};
vector<PI> adj[MX_N];

int main()
{
    int a, b, t;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for(int i=0; i<M; ++i) {
        cin >> a >> b >> t;
        adj[a].push_back(PI(t, b));
        adj[b].push_back(PI(t, a));
    }

    for(int i=1; i<=N; ++i) dist[i] = INF;

    priority_queue<PI> pq;
    pq.push(PI(0,1));
    dist[1] = 0;

    while(!pq.empty()) {
        int cur = pq.top().second;
        int curTime = -pq.top().first;
        pq.pop();
        
        if(isVisit[cur]) continue;
        isVisit[cur] = true;

        for(auto pi : adj[cur]) {
            int nxt = pi.second, tt = pi.first;
            if(dist[nxt] > curTime + tt) {
                dist[nxt] = curTime + tt;
                pre[nxt] = cur;
                pq.push(PI(-dist[nxt], nxt));
            }        
        }
    }
    cout << N-1 << '\n';
    for(int i=2; i<=N; ++i) {
        int node = i;
        while(!isChecked[node] && pre[node]) {
            isChecked[node] = true;
            cout << pre[node] << ' ' << node << '\n';
            node = pre[node];
        }
    }
}