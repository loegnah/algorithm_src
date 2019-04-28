#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <limits>
using namespace std;

const int V_MAX = 510;
const int INF = 10000000;

int V, E;
vector<pair<int, int> > delay;
int adj[V_MAX][V_MAX];
int tot[V_MAX][V_MAX];

void input()
{
	scanf("%d %d", &V, &E);
	
	int tmp;
	for (int i = 0; i < V; ++i) {
		scanf("%d", &tmp);
		delay.push_back(make_pair(tmp, i));
	}

	for (int i = 0; i < V; ++i) {
		for (int j = 0; j < V; ++j)
			adj[i][j] = INF;
		adj[i][i] = 0;
	}

	int a, b, c;
	for (int i = 0; i < E; ++i) {
		scanf("%d %d %d", &a, &b, &c);
		adj[a-1][b-1] = c;
		adj[b-1][a-1] = c;
	}
}

void floyd()
{
	sort(delay.begin(), delay.end());
	for(int i=0; i<V; ++i)
		for (int j = 0; j < V; ++j) {
			if (i == j)
				tot[i][j] = 0;
			else
				tot[i][j] = adj[i][j];
		}
	
	for (int k = 0; k < V; ++k) {
		int w = delay[k].second;
		int d = delay[k].first;
		for(int i=0; i<V; ++i)
			for (int j = 0; j < V; ++j) {
				adj[i][j] = min(adj[i][j], adj[i][w] + adj[w][j]);
				tot[i][j] = min(tot[i][j], adj[i][w] + d + adj[w][j]);
			}
	}
}

int main()
{
	input();
	floyd();
	int T;
	scanf("%d", &T);
	while (T--) {
		int src, dst;
		scanf("%d %d", &src, &dst);
		printf("%d\n", tot[src-1][dst-1]);
	}
}
