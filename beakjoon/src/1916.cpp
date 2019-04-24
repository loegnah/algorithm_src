#include <cstdio>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

const int INF = 1000000007;
int N,M,st,en;
vector<pair<int,int> > edge[1003];
int d[1003];
priority_queue<pair<int,int> > q;

void solve()
{
  int dist, node, n_dist, n_node;
  q.push(make_pair(0,st));
  while(!q.empty()) {
    dist = -q.top().first;
    node = q.top().second;
    q.pop();
    if(dist<d[node]) {
      d[node] = dist;
      for(int i=0; i<edge[node].size(); ++i) {
        n_dist = edge[node][i].first + dist;
        n_node = edge[node][i].second;
        if(n_dist < d[n_node])
          q.push(make_pair(-n_dist,n_node));
      }
    }
  }
}

int main()
{
  int a,b,c;
  scanf("%d %d",&N,&M);
  for(int i=0; i<M; ++i) {
    scanf("%d %d %d",&a,&b,&c);
    edge[a].push_back(make_pair(c,b));
  }
  for(int i=1; i<=N; ++i) d[i] = INF;
  scanf("%d %d",&st,&en);
  solve();
  printf("%d",d[en]);
}
