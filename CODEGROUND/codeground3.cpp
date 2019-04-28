#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int score[200001];

int main(int argc, char** argv)
{
	int T, N, K;
	int totScore;

	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (int test = 1; test <= T; ++test) {
		totScore = 0;
		scanf("%d %d", &N, &K);
		
		for (int i = 0; i < N; ++i) scanf("%d", &score[i]);
		sort(score, score + N);
		for (int i = 0; i < K; ++i) totScore += score[N - 1 - i];

		printf("Case #%d\n", test);
		printf("%d\n", totScore);
	}
	return 0;
}