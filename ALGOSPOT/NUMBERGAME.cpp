#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int SIZE = 51;
const int INTMIN = -2100000000;

int N, board[SIZE];
int cache[SIZE][SIZE];

int game(int l, int r)
{
	if (l > r) return 0;

	int &ret = cache[l][r];
	if (ret != INTMIN) return ret;

	ret = max(board[l] - game(l + 1, r), board[r] - game(l, r - 1));
	if (r - l >= 1) {
		ret = max(ret, -game(l + 2, r));
		ret = max(ret, -game(l, r - 2));
	}

	return ret;
}

int main()
{
	int C;

	scanf("%d", &C);
	for (int test = 0; test < C; ++test)
	{
		for (int y = 0; y < SIZE; ++y)
			for (int x = 0; x < SIZE; ++x)
				cache[y][x] = INTMIN;

		scanf("%d", &N);
		for (int n = 0; n < N; ++n) scanf("%d", board + n);
		printf("%d\n", game(0, N - 1));
	}
}