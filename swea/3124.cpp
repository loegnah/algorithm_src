#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
	int a, b, c;
	Edge() :a(0), b(0), c(0) {}
	Edge(int _a, int _b, int _c) : a(_a), b(_b), c(_c) {}
	bool operator < (const Edge& a) const { return c < a.c; }
};

const int MX_V = 100005;

int T, V, E, parent[MX_V];
vector<Edge> edges;



void input_init()
{
	int a, b, c;
	scanf("%d %d", &V, &E);

	for (int i = 1; i <= V; ++i) parent[i] = i;
	edges.clear();

	for (int i = 0; i < E; ++i) {
		scanf("%d %d %d", &a, &b, &c);
		edges.push_back(Edge(a, b, c));
	}

	sort(edges.begin(), edges.end());
}

int getPrt(int a) {
	if (parent[a] == a) return a;
	return parent[a] = getPrt(parent[a]);
}

void mergePrt(int a, int b) {
	a = getPrt(a);
	b = getPrt(b);
	if (a == b) return;
	parent[a] = b;
}

long long solve()
{
	int count = 0, idx = 0;
	long long cost = 0;

	while (count < V-1) {
		Edge& cur = edges[idx];
		idx++;

		if (getPrt(cur.a) == getPrt(cur.b)) continue;
		
		mergePrt(cur.a, cur.b);
		count++;
		cost += cur.c;
	}
	return cost;
}

int main()
{
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		input_init();
		printf("#%d %lld\n", tc, solve());
	}
}
