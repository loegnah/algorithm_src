#include <iostream>
#include <algorithm>
using namespace std;

const int V_MAX = 205;
const int INF = 555555555;

int V, M, N;
int adj[V_MAX][V_MAX];

void input()
{
	scanf("%d %d %d", &V, &M, &N);
	for (int i = 0; i < V; ++i) {
		for (int j = 0; j < V; ++j)
			adj[i][j] = INF;
		adj[i][i] = 0;
	}
	int a, b, c;
	for (int i = 0; i < M; ++i) {
		scanf("%d %d %d", &a, &b, &c);
		adj[a][b] = c;
		adj[b][a] = c;
	}
}

void floyd()
{
	for (int k = 0; k < V; ++k)
		for (int i = 0; i < V; ++i)
			for (int j = 0; j < V; ++j)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
}

bool update(int a, int b, int c)
{
	if (adj[a][b] <= c) return false;

	for (int i = 0; i < V; ++i)
		for (int j = 0; j < V; ++j)
			adj[i][j] = min(adj[i][j],
							min(adj[i][a] + c + adj[b][j],
								adj[i][b] + c + adj[a][j]));
	return true;
}

int solve() 
{
	int ans = 0;
	int a, b, c;

	floyd();
	for(int i=0; i<N; ++i) {
		scanf("%d %d %d", &a, &b, &c);
		if (!update(a, b, c))
			++ans;
	}
	return ans;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		input();
		printf("%d\n", solve());
	}
}