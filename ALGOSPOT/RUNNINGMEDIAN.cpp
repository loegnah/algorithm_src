#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

const int MOD = 20090711;
int N, a, b;

class RandNum
{
	int num, aa, bb;
public:
	RandNum(int aa, int bb) : num(1983), aa(aa), bb(bb) {}
	int make() {
		int ret = num;
		num = (num*(long long)a + b) % MOD;
		return ret;
	}
};

int solve()
{
	priority_queue<int, vector<int>, greater<int>> minHeap;
	priority_queue<int, vector<int>, less<int>> maxHeap;
	RandNum randNum(a, b);
	int ans = 0;
	int tmp1, tmp2;

	for (int i = 1; i <= N; ++i) {
		if (i % 2 == 1) maxHeap.push(randNum.make());
		else minHeap.push(randNum.make());

		if (i != 1 && maxHeap.top() > minHeap.top()) {
			tmp1 = maxHeap.top();
			tmp2 = minHeap.top();
			maxHeap.pop();
			minHeap.pop();
			maxHeap.push(tmp2);
			minHeap.push(tmp1);
		}
		ans = (ans + maxHeap.top()) % MOD;
	}
	return ans;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d", &N, &a, &b);
		printf("%d\n",solve());
	} 
}