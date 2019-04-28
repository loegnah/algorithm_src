#include <iostream>
using namespace std;

int M;
double N, P;

bool canPayOff(double monthPay)
{
	double remain = N;
	for (int day = 0; day < M; ++day) {
		remain = remain*(1.0 + P / 12.0 / 100.0) - monthPay;
		if (remain <= 0) return true;
	}
	return false;
}

double solve()
{
	double lo = 0;
	double hi = N*(1.0 + P / 12.0 / 100.0);
	double mid;

	for (int i = 0; i < 100; ++i) {
		mid = (lo + hi) / 2.0;
		if (canPayOff(mid))
			hi = mid;
		else
			lo = mid;
	}
	return mid;
}

int main()
{
	int T;

	cin >> T;
	for (int tc = 0; tc < T; ++tc) {
		cin >> N >> M >> P;
		printf("%.10lf\n", solve());
	}
}