#include <iostream>
#include <queue>
using namespace std;

int N, K;
unsigned int A;

unsigned int makeSignal()
{
	unsigned int ret = A % 10000 + 1;
	A = A * 214013u + 2531011u;
	return ret;
}

int solve()
{
	int sum = 0;
	int ret = 0;
	A = 1983;
	queue<unsigned int> signal;

	for (int tail = 1; tail <= N; ++tail) {
		signal.push(makeSignal());
		sum += signal.back();

		while (sum > K) {
			sum -= signal.front();
			signal.pop();
		}
		if (sum == K) ++ret;
	}
	return ret;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc) {
		scanf("%d %d", &K, &N);
		printf("%d\n",solve());
	}
}