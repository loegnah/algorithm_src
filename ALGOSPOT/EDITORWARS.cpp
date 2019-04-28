#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstring>
using namespace std;

class DisjointSet {
public:
	vector<int> parent, rank, enemy, size;

	DisjointSet(int n) : parent(n), rank(n, 0), enemy(n,-1), size(n,1) {
		for (int i = 0; i < n; ++i)
			parent[i] = i;
	}

	int find(int u) {
		if (u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}

	int merge(int u, int v) {
		if (u == -1 || v == -1) return max(u, v);
		u = find(u);
		v = find(v);
		if (u == v) return u;
		if (rank[u] > rank[v]) swap(u, v);
		if (rank[u] == rank[v]) rank[v] += 1;
		parent[u] = v;
		size[v] += size[u];
		return v;
	}

	bool ack(int u, int v) {
		u = find(u);
		v = find(v);
		if (enemy[u] == v) return false;
		int a = merge(u, v);
		int b = merge(enemy[u], enemy[v]);
		enemy[a] = b;
		if (b != -1) enemy[b] = a;
		return true;
	}
	bool dis(int u, int v) {
		u = find(u);
		v = find(v);
		if (u == v) return false;
		int a = merge(u, enemy[v]);
		int b = merge(v, enemy[u]);
		enemy[a] = b;
		enemy[b] = a;
		return true;
	}
};

int N, M;

int mxCalc(DisjointSet *ds)
{
	int mx = 0;
	
	for (int i = 0; i < N; ++i)	{
		if (ds->parent[i] != i) continue;
		int enemy = ds->enemy[i];
		if (enemy > i) continue;
		
		int teamSize = ds->size[i];
		int enemySize = (enemy == -1 ? 0 : ds->size[enemy]);
		mx += max(teamSize, enemySize);
	}
	return mx;
}

void solve()
{
	char ck[4];
	int a, b;
	DisjointSet *ds = new DisjointSet(N);
	bool ok, thisProblemFuckYouCase = false;

	for (int i = 1; i <= M; ++i) {
		scanf("%s %d %d", ck, &a, &b);

		if (!thisProblemFuckYouCase) {
			if (!strcmp(ck, "ACK")) ok = ds->ack(a, b);
			else ok = ds->dis(a, b);
		}
		

		if (!ok && !thisProblemFuckYouCase) {
			printf("CONTRADICTION AT %d\n", i);
			thisProblemFuckYouCase = true;
		}
	}
	if(!thisProblemFuckYouCase) printf("MAX PARTY SIZE IS %d\n", mxCalc(ds));
	return;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &M);
		solve();
	}
}