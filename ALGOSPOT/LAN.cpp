#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAX_V = 500;

vector<double> adj[MAX_V];
int V;
int N, M;
int x[MAX_V], y[MAX_V];

class DisjointSet {
public:
	vector<int> parent, rank;

	DisjointSet(int n) : parent(n), rank(n, 1) {
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
		if (rank[u] > rank[v]) swap(u, v);
		parent[u] = v;
		if (rank[u] == rank[v]) rank[u] += 1;
	}
};

double kruskal() {
	double ret = 0;

	vector<pair<double, pair<int, int> > > edges;
	for (int u = 0; u < V; ++u)
		for (int i = 0; i < V; ++i) {
			if (adj[u][i] < 0) continue;
			double cost = adj[u][i];
			edges.push_back(make_pair(cost, make_pair(u, i)));
		}

	sort(edges.begin(), edges.end());
	DisjointSet ds(V);
	for (int i = 0; i < edges.size(); ++i) {
		double cost = edges[i].first;
		int u = edges[i].second.first;
		int v = edges[i].second.second;
		if (ds.find(u) == ds.find(v)) continue;
		ds.merge(u, v);
		ret += cost;
	}
	return ret;
}

void solve()
{

}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &M);
		V = N;
		for (int i = 0; i < N; ++i) scanf("%d", x + i);
		for (int i = 0; i < N; ++i) scanf("%d", y + i);
		
		for (int i = 0; i < N; ++i) adj[i] = vector<double>(N,-1.0);

		for(int i=0; i<N; ++i)
			for (int j = 0; j < N; ++j) {
				if (i == j) continue;
				adj[i][j] = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
			}

		int a, b;
		for (int i = 0; i < M; ++i) {
			scanf("%d %d", &a, &b);
			adj[a][b] = 0;
			adj[b][a] = 0;
		}
		
		printf("%.10lf\n", kruskal());
	}
}