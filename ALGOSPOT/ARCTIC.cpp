#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int N;
double loc[101][2];
double dist[101][101];

void calcDist()
{
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			double xDist = loc[i][0] - loc[j][0];
			double yDist = loc[i][1] - loc[j][1];
			dist[i][j] = dist[j][i] = sqrt(xDist*xDist + yDist*yDist);
		}
	}
}

bool canAllVisit(double gap)
{
	vector<bool> isVisited(N, false);
	queue<int> dst;

	isVisited[0] = true;
	dst.push(0);
	int totVisit = 0, cur;
	
	while (!dst.empty()) {
		cur = dst.front();
		dst.pop();
		totVisit++;

		for (int next = 0; next < N; ++next) {
			if (!isVisited[next] && dist[cur][next] <= gap) {
				isVisited[next] = true;
				dst.push(next);
			}
		}
	}
	return totVisit == N;
}

void arctic()
{
	int C;

	scanf("%d", &C);
	for (int c = 0; c < C; ++c) {
		scanf("%d", &N);
		for (int n = 0; n < N; ++n) scanf("%lf %lf", &loc[n][0], &loc[n][1]);

		calcDist();

		double lo = 0, hi = 1414.21357, mid;
		for (int acc = 0; acc < 50; ++acc) {
			mid = (lo + hi) / 2.0;
			if (canAllVisit(mid)) hi = mid;
			else lo = mid;
		}
		printf("%.2lf\n", mid);
	}
}

int main() { arctic(); }