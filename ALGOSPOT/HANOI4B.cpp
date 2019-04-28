#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

const int COL = 4;
const int NO = -1;
int N;
int graph[(1 << 24)];

class bit {
public:
	static int get(int state, int idx) {
		return (state >> (idx * 2)) & 3;
	}
	static int set(int state, int idx, int value) {
		state &= ~(3 << (idx * 2));
		return (state | (value << (idx * 2)));
	}
};

class bi {
public:
	static int sgn(int x) {
		if (!x) return 0;
		return (x > 0 ? 1 : -1);
	}
	static int incr(int x) {
		if (x < 0) return x - 1;
		return x + 1;
	}
};

int solve(int ini, int goal)
{
	if (ini == goal) return 0;
	memset(graph, 0, sizeof(graph));
	queue<int> qu;
	qu.push(ini); qu.push(goal);
	graph[ini] = 1; graph[goal] = -1;

	while (!qu.empty()) {
		int cur = qu.front();
		qu.pop();
		int top[4] = { NO,NO,NO,NO };
		for (int i = N - 1; i >= 0; --i)
			top[bit::get(cur, i)] = i;
		
		for (int i = 0; i < COL; ++i) {
			if (top[i] != NO) {
				for (int j = 0; j < COL; ++j) {
					if ((i != j) && (top[j] == NO || top[j] > top[i])) {
						int next = bit::set(cur, top[i], j);
						if (graph[next] == 0) {
							graph[next] = bi::incr(graph[cur]);
							qu.push(next);
						}
						else if (bi::sgn(graph[cur]) != bi::sgn(graph[next])) {
							return abs(graph[cur]) + abs(graph[next]) - 1;
						}
					}
				}
			}
		}
	}
	return -1;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		int ini = 0, goal = 0;
		int m, tmp;

		scanf("%d", &N);
		for (int i = 0; i < COL; ++i) {
			scanf("%d", &m);
			for (int k = 0; k < m; ++k) {
				scanf("%d", &tmp);
				ini |= (i << ((tmp-1) * 2));
			}
		}
		for (int i = 0; i < N; ++i)
			goal |= (3 << (i * 2));
		printf("%d\n",solve(ini, goal));
	}
}