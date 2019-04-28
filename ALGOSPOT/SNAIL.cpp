#include <iostream>
#include <cstring>
using namespace std;

int N, M;
double cache[1001][2001];

double path(int day, int meter);

int main()
{
	int C;

	scanf("%d", &C);
	for (int test = 0; test < C; ++test) {
		scanf("%d %d", &N, &M);

		for (int i = 0; i <= M; ++i)
			for (int j = 0; j <= M * 2 + 1; ++j)
				cache[i][j] = -1.0;

		printf("%.10lf\n", path(0, 0));
	}
}

double path(int day, int meter)
{
	if (day == M) return meter >= N ? 1.0 : 0;

	double &ret = cache[day][meter];
	if(ret != -1.0) return ret;

	return ret = 0.25*path(day + 1, meter + 1) + 0.75*path(day + 1, meter + 2);
}