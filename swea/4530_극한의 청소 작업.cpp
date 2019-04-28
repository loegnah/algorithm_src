#include <cstdio>
#include <cmath>
using namespace std;

typedef long long llong;

const llong LL_MAX = 1000000000000LL;
const llong LL_TEN = 10LL;

llong a, b, fourCount[14];

inline bool sign(llong a) {
	return a > 0 ? true : false;
}

void preCalc()
{
	fourCount[0] = 0;
	llong num = 1;
	for (llong i = 1; i <= 13; ++i) {
		fourCount[i] = fourCount[i - 1] * 9 + num;
		num *= LL_TEN;
	}
}

long long calcFour(long long num)
{
	llong ret = 0, ex = 1LL;
	int t = 0;
	while (num) {
		int k = num % LL_TEN;
		for (int i = 0; i < k; ++i) {
			if (i != 4) ret += fourCount[t];
			else ret += ex;
		}
		ex *= LL_TEN;
		num /= LL_TEN;
		t++;
	}
	return ret;
}

int main()
{
	int T;
	llong ans;
	setbuf(stdout, NULL);
	preCalc();
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		scanf("%lld %lld", &a, &b);

		bool aSign = sign(a);
		bool bSign = sign(b);
		a = abs(a);
		b = abs(b);
		llong cnt1 = a - calcFour(a);
		llong cnt2 = b - calcFour(b);

		if (aSign != bSign) ans = cnt1 + cnt2 - 1;
		else ans = abs(cnt1 - cnt2);

		printf("#%d %lld\n", tc, ans);
	}
}