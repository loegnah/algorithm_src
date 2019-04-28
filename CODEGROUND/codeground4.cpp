#include <cstdio>
#include <iostream>

#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

int score[20] = { 6,13,4,18,1,20,5,12,9,14,11,8,16,7,19,3,17,2,15,10 };

double calcR(int x, int y)
{
	return sqrt(x*x + y*y);
}

int calcScore(int x, int y)
{
	double degree = atan2((double)y, (double)x) * 180 / M_PI + 9.0;
	if (degree < 0) degree = degree + 360;
	return score[(int)degree / 18];
}

int main()
{
	setbuf(stdout, NULL);
	int T, N, A, B, C, D, E;
	int x, y, totScore, baseScore;
	double r;

	scanf("%d", &T);
	for (int test = 1; test <= T; ++test) {
		scanf("%d %d %d %d %d", &A, &B, &C, &D, &E);
		scanf("%d", &N);
		totScore = 0;

		for (int i = 0; i < N; ++i) {
			scanf("%d %d", &x, &y);
			r = calcR(x, y);
			baseScore = calcScore(x, y);

			if (r < A) totScore += 50;
			else if (r < B) totScore += baseScore;
			else if (r < C) totScore += baseScore * 3;
			else if (r < D) totScore += baseScore;
			else if (r < E) totScore += baseScore * 2;
		}

		printf("Case #%d\n", test);
		printf("%d\n", totScore);
	}
}