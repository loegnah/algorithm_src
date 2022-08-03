#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

class DisjointSet {
public:
	vector<int> parent, rank;

	DisjointSet(int n) : parent(n), rank(n,1) {
		for (int i = 0; i < n; ++i)
			parent[i] = i;
	}

	int find(int u) {
		if (u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}

	void merge(int u, int v) {
		u = find(u);
		v = find(v);
		if (u == v) return;
		if (rank[u] > rank[v]) parent[v] = u;
		else parent[u] = v;
		if (rank[u] == rank[v]) rank[u] += 1;
	}
};

int N,M;
vector<pair<int,pair<int,int> > > edges;

int solve()
{
  int a,b,c, ret = 0;
  for(int i=0; i<M; ++i) {
    scanf("%d %d %d",&a,&b,&c);
    edges.push_back(make_pair(c,make_pair(a-1,b-1)));
  }
  sort(edges.begin(),edges.end());
  DisjointSet ds(N);
  for(int i=0; i<M; ++i) {
    int c = edges[i].first, u = edges[i].second.first, v = edges[i].second.second;
    if(ds.find(u) == ds.find(v)) continue;
		ds.merge(u,v);
    ret += c;
  }
  return ret;
}

int main()
{
  scanf("%d",&N);
  scanf("%d",&M);
  printf("%d",solve());
}
