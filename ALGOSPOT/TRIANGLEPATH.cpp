#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int cache[100][100];
int tri[100][100];
int N = 0;

int TriPath(int y, int x)
{
	if (y == N - 1) return tri[y][x];
	int& ret = cache[y][x];
	if (ret != -1) return ret;

	return ret = tri[y][x] + max(TriPath(y + 1, x), TriPath(y + 1, x + 1));
}

int main()
{
	int C;

	cin >> C;
	while (C-- > 0) {
		memset(cache, -1, sizeof(cache));
		cin >> N;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j <= i; ++j) {
				scanf("%d", &tri[i][j]);
			}
		}
		cout << TriPath(0, 0) << endl;
	}
}