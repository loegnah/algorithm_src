#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char **argv)
{
	int T,N, tmp, ans;

	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (int test = 1; test <= T; ++test) {
		scanf("%d", &N);
		ans = 0;
		for (int i = 0; i < N; ++i) {
			scanf("%d", &tmp);
			ans = ans ^ tmp;
		}

		printf("Case #%d\n", test);
		printf("%d\n", ans);
	}

	return 0;
}