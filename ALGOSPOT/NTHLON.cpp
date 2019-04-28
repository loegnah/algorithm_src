#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
using namespace std;

int M;
vector<pair<int,int> > adj[405];
const int START = 401, V = 402;
const int INF = 987654321;
int a[500], b[500];

int vtx(int n) { return n+200; }

void makeGraph()
{
	for(int i=0; i<V; ++i) adj[i].clear();
	
	for(int i=0; i<M; ++i)
		adj[START].push_back(make_pair(vtx(a[i]-b[i]),a[i]));
	
	for(int d=-200; d<=200; ++d) {
		for(int i=0; i<M; ++i) {
			int next = d + a[i] - b[i];
			if(abs(next) > 200) continue;
			adj[vtx(d)].push_back(make_pair(vtx(next),a[i]));
		}
	}
}

vector<int> dijkstra(int st)
{
	vector<int> dist(V,INF);
	vector<bool> isVisited(V,false);
	
	dist[st] = 0;
	while(true) {
		int closest = INF;
		int here;
		for(int i=0; i<V; ++i) {
			if(dist[i] < closest && !isVisited[i]) {
				here = i;
				closest = dist[i];	
			}
		}
		if(closest == INF) break;
		
		isVisited[here] = true;
		for(int i=0; i<adj[here].size(); ++i) {
			int there = adj[here][i].first;
			if(isVisited[there]) continue;
			int nextDist = dist[here] + adj[here][i].second;
			dist[there] = min(dist[there], nextDist);
		}
	}
	return dist;
}

int solve()
{
	makeGraph();
	vector<int> dist = dijkstra(START);
	
	int ans = dist[vtx(0)];
	if(ans == INF) printf("IMPOSSIBLE\n");
	else printf("%d\n",ans);
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&M);
		for(int i=0; i<M; ++i)
			scanf("%d %d",a+i, b+i);
		solve();
	}
}

