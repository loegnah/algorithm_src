#include <cstdio>
using namespace std;

const int x[10] = { 0,1,2,2,4,0,4,0,0,5 };
int T, M, N;

int solve()
{
	int a = M / 4, b = N / 4;
	int c = M % 4, d = N % 4;

	return 8 * a*b + 2 * b*c + 2 * a*d + x[c*d];
}

int main()
{
	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		scanf("%d %d", &N, &M);
		printf("#%d %d\n", tc, solve());
	}
}