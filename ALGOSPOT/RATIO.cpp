#include <iostream>
using namespace std;

const long long maxGame = 2000000000;
long long N, M;

bool canRaise1Point(long long winRate, long long gameNum)
{
	
	long long totGame = gameNum + N;
	long long winGame = gameNum + M;
	long long newWinRate = winGame * 100 / totGame;

	if ((newWinRate - winRate )>= 1)
		return true;
	else
		return false;
}

long long solve()
{
	long long winRate = M * 100 / N;
	if (!canRaise1Point(winRate, maxGame))
		return -1;

	long long lo = 1;
	long long hi = maxGame;
	long long mid;
	for (int i = 0; i < 100; ++i) {
		mid = (lo + hi) / 2;
		if (canRaise1Point(winRate, mid))
			hi = mid;
		else
			lo = mid;
	}
	return hi;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc) {
		scanf("%lld %lld", &N, &M);
		printf("%lld\n", solve());
	}
}