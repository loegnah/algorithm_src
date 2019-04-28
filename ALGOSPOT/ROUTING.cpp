#include <iostream>
#include <vector>
#include <utility>
#include <limits>
#include <queue>
#include <cmath>
using namespace std;

const double DINF = numeric_limits<double>::max();
int N, M;
vector<vector<pair<double, int> > > adj;

double solve()
{
	vector<double> dist(N, DINF);
	priority_queue<pair<double, int> > qu;

	dist[0] = 1.0;
	qu.push(make_pair(-dist[0],0));
	while (!qu.empty()) {
		int here = qu.top().second;
		double cost = -qu.top().first;
		qu.pop();
		if (cost > dist[here]) continue;
		for (int i = 0; i < adj[here].size(); ++i) {
			int there = adj[here][i].second;
			double cost2 = adj[here][i].first * cost;
			if (cost2 < dist[there]) {
				dist[there] = cost2;
				qu.push(make_pair(-cost2, there));
			}
		}
	}
	return dist[N - 1];

}

int main()
{
	int T;
	scanf("%d", &T);
	
	while (T--) {
		scanf("%d %d", &N, &M);
		adj = vector<vector<pair<double, int> > >(N);
		int a, b;
		double w;
		for (int i = 0; i < M; ++i) {
			scanf("%d %d %lf", &a, &b, &w);
			adj[a].push_back(make_pair(w, b));
			adj[b].push_back(make_pair(w, a));
		}
		double ans = solve();
		printf("%.10lf\n", ans);
	}
}