#include <iostream>
using namespace std;

int N, D, P, Q, T;
double cache[51][101];
bool isConnt[50][50];
int ctConnt[50];
double ans[50];

double prob(int cur, int day)
{
	if (day == D) return (cur == P) ? 1.0 : 0.0;

	double &ret = cache[cur][day];
	if (ret > -0.5) return ret;

	ret = 0.0;
	for (int next = 0; next < N; ++next) 
		if (isConnt[cur][next]) ret += prob(next, day + 1) / ctConnt[next];

	return ret;
}

void resetCache()
{
	for (int i = 0; i < N; ++i)
		for (int j = 0; j <= D; ++j)
			cache[i][j] = -1.0;
}

int main()
{
	int C, end, ct;

	scanf("%d", &C);
	for (int test = 0; test < C; ++test) {
		scanf("%d %d %d", &N, &D, &P);

		for (int i = 0; i < N; ++i) {
			ct = 0;
			for (int j = 0; j < N; ++j) {
				scanf("%d", &isConnt[i][j]);
				if (isConnt[i][j]) ++ct;
			}
			ctConnt[i] = ct;
		}

		scanf("%d", &T);
		for (int i = 0; i < T; ++i) {
			resetCache();
			scanf("%d", &end);
			ans[i] = prob(end, 0);
		}
		for (int i = 0; i < T; ++i) printf("%.8lf ", ans[i]);
		printf("\n");
	}
}