#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > adj;
vector<bool> isVisited;

const int WTC = 0;
const int UWTC = 1;
const int IST = 2;

int N, G;
int ans;

int dfs(int here)
{
	isVisited[here] = true;
	int state[3] = { 0,0,0 };

	for (int i = 0; i < adj[here].size(); ++i) {
		int there = adj[here][i];
		if (!isVisited[there])
			state[dfs(there)] += 1;
	}
	if (state[UWTC]) {
		++ans;
		return IST;
	}
	if (state[IST])
		return WTC;
	return UWTC;
}

void dfsAll()
{
	isVisited = vector<bool>(N, false);
	for (int i = 0; i < N; ++i) {
		if (!isVisited[i] && dfs(i) == UWTC) {
			++ans;
		}
	}
}

int main()
{
	int T, a, b;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &G);
		adj = vector<vector<int> >(N, vector<int>(0));
		ans = 0;

		for (int i = 0; i < G; ++i) {
			scanf("%d %d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		dfsAll();
		printf("%d\n", ans);
	}
}