#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

const int MX_N = 100000;
const long long MX_DST = 100000LL * 1000000LL;

int t, n, m, st, en;
long long dst[MX_N + 3];
vector<pair<int,long long> > adj[MX_N + 3];
queue<pair<long long, int> > qu;

void kruskal()
{
	int cur, nxt;
	long long d, nd;

	qu.push(make_pair(0, st));
	while (!qu.empty()) {
		d = -qu.front().first;
		cur = qu.front().second;
		qu.pop();

		if (dst[cur] < d) continue;
		dst[cur] = d;
		
		for (int i = 0; i < adj[cur].size(); ++i) {
			nxt = adj[cur][i].first;
			nd = adj[cur][i].second;
			if (d + nd < dst[nxt]) qu.push(make_pair(-(d+nd), nxt));
		}
	}
}

int main()
{
	int a, b;
	long long c;

//	freopen("input.txt", "r", stdin);
	scanf("%d", &t);
	for (int tc = 1; tc <= t; ++tc) {
		scanf("%d %d %d %d", &n, &m, &st, &en);

		for (int i = 1; i <= n; ++i) {
			adj[i].clear(); 
			dst[i] = MX_DST;
		}
		qu = queue<pair<long long, int> >();

		for (int i = 0; i < m; ++i) {
			scanf("%d %d %lld", &a, &b, &c);
			adj[a].push_back(make_pair(b, c));
			adj[b].push_back(make_pair(a, c));
		}

		kruskal();

		printf("#%d %lld\n", tc, dst[en]);
	}
}