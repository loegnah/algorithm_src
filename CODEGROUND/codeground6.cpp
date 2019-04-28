#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int N, K;
long long stScore[200001];
string path;

long long calcScore(int y, int x) {
	long long ret;
	int a = 0;

	if ((y + x + 1) > N) a = y + x + 1 - N;

	if ((y + x) % 2 == 0)
		ret = stScore[y + x] + x - a;
	else
		ret = stScore[y + x] + y - a;
	return ret;
}

int main(int argc, char** argv)
{
	int T, x, y;
	long long ans;
	char direct;
	

	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (int test = 1; test <= T; ++test) {
		scanf("%d %d", &N, &K);
		cin >> path;

		stScore[0] = 1;
		for (int n = 1; n < N; ++n) stScore[n] = stScore[n - 1] + n;
		for (int n = N; n < 2 * N - 1; ++n) stScore[n] = stScore[n - 1] + (2 * N - n);

		x = y = 0;
		ans = 1;
		for (int k = 0; k < K; ++k) {
			direct = path[k];
			if (direct == 'U') y -= 1;
			else if (direct == 'D') y += 1;
			else if (direct == 'L') x -= 1;
			else x += 1;
			ans += calcScore(y, x);
		}
		
		printf("Case #%d\n", test);
		printf("%lld\n", ans);
	}
}