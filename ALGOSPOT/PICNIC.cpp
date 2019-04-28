#include <iostream>
#include <cstring>
using namespace std;

bool Pair[10][10] = {};
int n;

int countPair(bool isPositioned[10])
{
	int start = -1;
	for (int i = 0; i < n; ++i) {
		if (!isPositioned[i]) {
			start = i;
			break;
		}
	}
	if (start == -1) return 1;
	int ret = 0;
	for (int cur = start + 1; cur < n; ++cur) {
		if (!isPositioned[cur] && Pair[start][cur]) {
			isPositioned[start] = isPositioned[cur] = true;
			ret += countPair(isPositioned);
			isPositioned[start] = isPositioned[cur] = false;
		}
	}
	return ret;
}

int main()
{
	int C, m;
	int a, b, ret = 0;
	bool isPositioned[10] = { false };

	cin >> C;
	while (C-- > 0) {
		memset(Pair, false, sizeof(Pair));
		cin >> n >> m;
		for (int i = 0; i < m; ++i) {
			cin >> a >> b;
			Pair[a][b] = true;
			Pair[b][a] = true;
		}
		cout << countPair(isPositioned) << endl;
	}
}