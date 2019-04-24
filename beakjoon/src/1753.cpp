#include <cstdio>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

const int INF = 987654321;
int V,E,K;
vector<pair<int,int> > edge[20003];
int d[20003];
priority_queue<pair<int,int> > q;

void solve()
{
  int dist, node, n_dist, n_node;
  q.push(make_pair(0,K));
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
  scanf("%d %d %d",&V,&E,&K);
  for(int i=0; i<E; ++i) {
    scanf("%d %d %d",&a,&b,&c);
    edge[a].push_back(make_pair(c,b));
  }
  for(int i=1; i<=V; ++i) d[i] = INF;
  solve();
  for(int i=1; i<=V; ++i) {
    if(d[i] == INF) printf("INF\n");
    else printf("%d\n",d[i]);
  }
}
