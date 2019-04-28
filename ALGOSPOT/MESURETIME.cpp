#include <iostream>
#include <vector>
using namespace std;

class FenwickTree {
public:
	vector<int> tree;

	FenwickTree(int n) : tree(n + 1) {}
	
	int sum(int pos) {
		int ret = 0;
		++pos;

		while (pos > 0) {
			ret += tree[pos];
			pos &= (pos - 1);
		}
		return ret;
	}

	void add(int pos, int val) {
		++pos;
		while (pos < tree.size()) {
			tree[pos] += val;
			pos += (pos & -pos);
		}
	}
};

int N;

void solve()
{
	long long ans = 0;
	FenwickTree fw(1000001);
	int input;
	
	for (int i = 0; i < N; ++i) {
		scanf("%d", &input);
		ans += fw.sum(1000000) - fw.sum(input);
		fw.add(input, 1);
	}

	printf("%lld\n", ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		solve();
	}
	
}