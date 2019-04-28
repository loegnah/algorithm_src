#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int score[300001];

int main(int argc, char** argv)
{
	int T, N, maxNum, ans;

	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (int test = 1; test <= T; ++test) {
		scanf("%d", &N);
		maxNum = -1;
		ans = 0;

		for (int i = 0; i < N; ++i)
			scanf("%d", &score[i]);
		
		sort(score, score + N);
		for (int i = N - 1; i >= 0; --i)
			if (maxNum < score[i] + N - i)
				maxNum = score[i] + N - i;

		for (int i = 0; i < N; ++i) 
			if (maxNum <= score[i] + N)
				++ans;

		printf("Case #%d\n", test);
		printf("%d\n", ans);
	}

	return 0;
}