#include <iostream>
using namespace std;

int N, M;
double camLoc[201];

bool canSetCam(double gap)
{
	int settedCam = 0;
	double maxGap = -1;
	for (int m = 0; m < M; ++m) {
		if (maxGap <= camLoc[m]) {
			++settedCam;
			maxGap = camLoc[m] + gap;
		}
	}
	return settedCam >= N;
}

void darpa()
{
	int C;

	scanf("%d", &C);
	for (int c = 0; c < C; ++c) {
		scanf("%d %d", &N, &M);
		for (int m = 0; m < M; ++m) scanf("%lf", camLoc + m);

		double lo = 0, hi = 241, mid;
		for (int accuracy = 0; accuracy < 50; ++accuracy) {
			mid = (lo + hi) / 2.0;
			if (canSetCam(mid)) lo = mid;
			else hi = mid;
		}

		printf("%.2lf\n", mid);
	}
}

int main()
{
	darpa();
}