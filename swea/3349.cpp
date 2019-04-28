#include <cstdio>
using namespace std;

int W, H, N, x1, x2, y1, y2;

int _max(int a, int b) { return a > b ? a : b; }
int _abs(int a) { return a >= 0 ? a : -a; }

int main()
{
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		scanf("%d %d %d", &W, &H, &N);

		int moveCt = 0;
		scanf("%d %d", &x1, &y1);
		for (int i = 1; i < N; ++i) {
			scanf("%d %d", &x2, &y2);
			if (x1 < x2 && y1 < y2) moveCt += _max(x2 - x1, y2 - y1);
			else if (x1 > x2 && y1 > y2) moveCt += _max(x1 - x2, y1 - y2);
			else moveCt += _abs(x1 - x2) + _abs(y1 - y2);

			x1 = x2;
			y1 = y2;
		}
		printf("#%d %d\n", tc, moveCt);
	}
}