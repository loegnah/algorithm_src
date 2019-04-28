#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N, tri[100][100];
int cache[101][101];
int ctCache[101][101];

int path(int y, int x);
int count(int y, int x);

int main()
{
	int C;

	scanf("%d", &C);
	for (int test = 0; test < C; ++test) {
		memset(cache, -1, sizeof(cache));
		memset(ctCache, -1, sizeof(ctCache));
		scanf("%d", &N);

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j <= i; ++j) scanf("%d", &tri[i][j]);	
		}
		cout << count(0, 0) << endl;
	}
}

int path(int y, int x)
{
	if (y == N - 1) return cache[y][x] = tri[y][x];

	int &ret = cache[y][x];
	if (ret != -1) return ret;

	ret = tri[y][x] + max(path(y + 1, x), path(y + 1, x + 1));
	return ret;
}

int count(int y, int x)
{
	if (y == N - 1) return 1;

	int &ret = ctCache[y][x];
	if (ret != -1) return ret;

	ret = 0;
	int downPathCt = path(y + 1, x);
	int righPathCt = path(y + 1, x + 1);
	if (downPathCt >= righPathCt) ret += count(y + 1, x);
	if (downPathCt <= righPathCt) ret += count(y + 1, x + 1);
	return ret;
}