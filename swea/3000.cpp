#include <cstdio>
#include <queue>
#include <functional>
#include <vector>
using namespace std;

const int MOD = 20171109;

int N, A;
priority_queue<int> maxHp;
priority_queue<int, vector<int>, greater<int> > minHp;

void _swap(int &n1, int &n2) {
	if (n1 > n2) {
		int tmp = n1;
		n1 = n2;
		n2 = tmp;
	}
}

void input_init()
{
	scanf("%d %d", &N, &A);
	maxHp = priority_queue<int>();
	minHp = priority_queue<int, vector<int>, greater<int> >();
}

int solve()
{
	int n1, n2, ans = 0;
	maxHp.push(A);

	for (int n = 0; n < N; ++n) {
		scanf("%d %d", &n1, &n2);
		_swap(n1, n2);

		if (n2 < maxHp.top()) {
			maxHp.push(n1); maxHp.push(n2);
			minHp.push(maxHp.top());
			maxHp.pop();
		}
		else if (maxHp.top() < n1) {
			minHp.push(n1); minHp.push(n2);
			maxHp.push(minHp.top());
			minHp.pop();
		}
		else {
			maxHp.push(n1);
			minHp.push(n2);
		}
		ans = (ans + maxHp.top()) % MOD;
	}
	return ans;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		input_init();
		printf("#%d %d\n", tc, solve());
	}
}