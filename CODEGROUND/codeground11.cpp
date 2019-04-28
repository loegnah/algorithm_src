#include <iostream>
#include <cstdio>
using namespace std;

int stone[1000010];
int N, K;

int solve()
{
	int cur = 0, stNum =  0;
	int maxLoc = stone[N];
	int ans = 0;
	bool ck = true;
	bool conti = true;

	while (cur < maxLoc) {
		ck = false;

		while (true) {
			conti = false;
			if (stNum >= N) break;

			if (stone[stNum+1] - cur > K) {
				conti = true;
				break;
			}
			++stNum;
			ck = true;
		}

		if (!ck) return -1;

		++ans;
		if (!conti) {
			if (stone[stNum] - cur > K)
				--stNum;
			else
				return ans;
		}
		cur = stone[stNum];
	}
}

int main(int argc, char** argv)
{
	setbuf(stdout, NULL);
	int T;
	
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		scanf("%d", &N);
		for (int n = 1; n <= N; ++n)
			scanf("%d", stone + n);
		scanf("%d", &K);

		printf("Case #%d\n", tc);
		printf("%d\n", solve());
	}
	return 0;
}