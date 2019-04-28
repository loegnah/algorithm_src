#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> ft, md, ans;



void solve(int ftStart,int size, int mdStart)
{
	int leftSize, rightSize;

	if (size > 0) {
		for (int i = 0; i < size; ++i) {
			if (ft[ftStart] == md[mdStart + i]) {
				leftSize = i;
				rightSize = size - 1 - leftSize;
				break;
			}
		}

		if (leftSize > 0) solve(ftStart + 1, leftSize, mdStart);
		if (rightSize > 0) solve(ftStart + 1 + leftSize, rightSize, mdStart + 1 + leftSize);
	}
	ans.push_back(ft[ftStart]);
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc) {
		scanf("%d", &N);
		
		ft.resize(N);
		md.resize(N);
		ans.resize(0);

		int tmp;
		for (int i = 0; i < N; ++i) {
			scanf("%d", &tmp);
			ft[i] = tmp;
		}
		for (int i = 0; i < N; ++i) {
			scanf("%d", &tmp);
			md[i] = tmp;
		}

		solve(0,N,0);
		for (int i = 0; i < N; ++i) printf("%d ", ans[i]);
		printf("\n");
	}
}