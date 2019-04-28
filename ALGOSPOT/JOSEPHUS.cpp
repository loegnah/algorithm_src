#include <iostream>
#include <list>
using namespace std;

int N, K;
int ans[2];

void solve()
{
	list<int> soldier;
	
	for (int n = 1; n <= N; ++n)
		soldier.push_back(n);

	int sizeSol = N;
	list<int>::iterator pSol = soldier.begin();
	while (sizeSol != 2) {
		pSol = soldier.erase(pSol);
		if (pSol == soldier.end()) pSol = soldier.begin();
		for (int i = 1; i < K; ++i) {
			++pSol;
			if (pSol == soldier.end()) pSol = soldier.begin();
		}
		--sizeSol;
	}
	ans[0] = soldier.front();
	ans[1] = soldier.back();
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc) {
		scanf("%d %d", &N, &K);
		solve();
		printf("%d %d\n", ans[0], ans[1]);
	}
}