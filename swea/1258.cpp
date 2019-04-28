#include <cstdio>
using namespace std;

const int MX_N = 100;

struct Order {
	int mult, row, idx;
};

int board[MX_N + 1][MX_N + 1] = { 0, }, check[MX_N][MX_N];
int ax[MX_N], ay[MX_N];
Order order[MX_N+1];

bool _comp(const Order &a, const Order &b) {
	return (a.mult<b.mult || (a.mult==b.mult && a.row<b.row));
}

void _swap(int a, int b)
{
	Order tmp = order[a];
	order[a] = order[b];
	order[b] = tmp;
}

void _sort(int len)
{
	for (int i = 0; i < len - 1; ++i) {
		int m = i;
		for (int j = i + 1; j < len; ++j) {
			m = _comp(order[m], order[j]) ? m : j;
		}
		_swap(i, m);
	}
}

int main()
{
	int t, y, x, n, lx, ly, xlen, ylen, idx;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; ++tc) {
		scanf("%d", &n);

		for (y = 0; y<n; ++y) for (x = 0; x<n; ++x) {
			scanf("%d", &board[y][x]);
			check[y][x] = 0;
		}

		idx = 0;
		y = 0;
		while (y<n) {
			x = 0;
			while (x<n) {
				while (check[y][x]) x += check[y][x] + 1;

				if (board[y][x]) {
					lx = x + 1;
					while (board[y][lx]) lx++;
					xlen = lx - x;

					ly = y;
					while (board[ly][x]) check[ly++][x] = xlen;
					ylen = ly - y;

					ax[idx] = xlen;
					ay[idx] = ylen;
					order[idx] = { xlen*ylen,ylen,idx };
					idx++;
					x = lx + 1;
				}
				else x++;
			}
			y++;
		}
		_sort(idx);

		printf("#%d %d ", tc, idx);
		for (int i = 0; i<idx; ++i) {
			int j = order[i].idx;
			printf("%d %d ", ay[j], ax[j]);
		}
		printf("\n");
	}
}
