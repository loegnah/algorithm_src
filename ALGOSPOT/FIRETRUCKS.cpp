#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

const int START = 0;
const int MAX_V = 1010;
const int INF = numeric_limits<int>::max();

int V, E, N, M;
vector<pair<int, int> > adj[MAX_V];
vector<int> fire, save;

void input()
{
	scanf("%d %d %d %d", &V, &E, &N, &M);
	for (int i = 0; i < MAX_V; ++i) adj[i].clear();

	int a, b, t, tmp;
	for (int i = 0; i < E; ++i) {
		scanf("%d %d %d", &a, &b, &t);
		adj[a].push_back(make_pair(b, t));
		adj[b].push_back(make_pair(a, t));
	}

	fire.clear(); save.clear();
	for (int i = 0; i < N; ++i) {
		scanf("%d", &tmp);
		fire.push_back(tmp);
	}
	for (int i = 0; i < M; ++i) {
		scanf("%d", &tmp);
		save.push_back(tmp);
	}
}

void startSet()
{
	for (int i = 0; i < save.size(); ++i) {
		adj[START].push_back(make_pair(save[i],0));
	}
}

vector<int> dijkstra()
{
	vector<int> dist(V+1, INF);
	priority_queue<pair<int, int> > qu;

	dist[START] = 0;
	qu.push(make_pair(0, START));
	while (!qu.empty()) {
		int cur = qu.top().second;
		int cost = -qu.top().first;
		qu.pop();

		if (cost > dist[cur]) continue;
		
		for (int i = 0; i < adj[cur].size(); ++i) {
			int next = adj[cur][i].first;
			int nextCost = cost + adj[cur][i].second;
			if (nextCost < dist[next]) {
				dist[next] = nextCost;
				qu.push(make_pair(-nextCost,next));
			}
		}
	}
	return dist;
}

int solve()
{
	startSet();
	vector<int> dist = dijkstra();

	int aa, ans = 0;
	for (int i = 0; i < fire.size(); ++i)
		ans += dist[fire[i]];
	return ans;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		input();
		printf("%d\n",solve());
	}
}