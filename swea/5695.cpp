#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int N, frnd[1003], couple[1003], isVisited[1003];
int cycleLen;
vector<int> invFrnd[1003];

void coupleCheck()
{
	for (int i = 1; i <= N; ++i) {
		if (i == frnd[frnd[i]]) {
			couple[i] = frnd[i];
			couple[frnd[i]] = i;
		}
	}
}

int maxTreeLen(int cur, int expt) 
{
	int ret = 0;
	isVisited[cur] = -1;
	for (int next : invFrnd[cur]) {
		if (next == expt) continue;
		ret = max(ret, maxTreeLen(next, 0));
	}
	return ret + 1;
}

void cycleCheck(int cur, int pathLen)
{
	if (isVisited[cur] > 0) {
		cycleLen = max(cycleLen, pathLen - isVisited[cur]);
		return;
	}
	if (isVisited[cur] == -1) return;

	isVisited[cur] = pathLen;
	cycleCheck(frnd[cur], pathLen + 1);
	isVisited[cur] = -1;
}

int main()
{
	int T;
	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		scanf("%d", &N);

		for (int i = 1; i <= N; ++i) invFrnd[i].clear();
		memset(isVisited, 0, sizeof(isVisited));

		for (int i = 1; i <= N; ++i) {
			scanf("%d", frnd + i);
			invFrnd[frnd[i]].push_back(i);
		}
		
		
		memset(couple, 0, sizeof(couple));
		coupleCheck();
		
		int coupleCnt = 0;
		for (int i = 1; i <= N; ++i) {
			if (couple[i]) {
				coupleCnt += maxTreeLen(i, couple[i]) + maxTreeLen(couple[i], i);
				couple[i] = 0;
				couple[frnd[i]] = 0;
			}
		}

		cycleLen = 0;
		for (int i = 1; i <= N; ++i) {
			if (isVisited[i]) continue;
			cycleCheck(i, 1);
		}
		
		printf("#%d %d\n", tc, max(coupleCnt, cycleLen));
	}
}