#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

typedef priority_queue<long long, vector<long long>, greater<long long>> PQ;
const long long DIV = 1000000007;
int N;
PQ eng;

void input() {
	long long ipt;
	eng = PQ();
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%lld", &ipt);
		eng.push(ipt);
	}
}

long long mult(long long a, long long b) { return ((a%DIV)*(b%DIV)) % DIV;}

long long solve() {
	long long a, b, ab;
	long long sum = 1;

	while (eng.size() > 1) {
		a = eng.top(); eng.pop();
		b = eng.top(); eng.pop();
		ab = a*b;
		eng.push(ab);
		sum = mult(sum, ab);
	}
	return sum;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		input();
		printf("%lld\n",solve());

	}
}

