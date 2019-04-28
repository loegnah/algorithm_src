#include <iostream>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int N, longest;
int relation[101][101];  // -1 : self , 0 : no relation, 1 : child , 2 : parent
int wall[101][3];
vector<pair<int, int> > srt;

int comparePair(pair<int, int>& a, pair<int, int>& b)
{
	return a.first > b.first;
}

bool isIncluded(int a, int b)
{
	int x = wall[a][0] - wall[b][0];
	int y = wall[a][1] - wall[b][1];
	int r = wall[a][2] + wall[b][2];
	return (x*x + y*y) < r*r;
}

void chkRelation(int idx)
{
	int n = srt[idx].second;

	for (int i = idx+1; i < N; ++i) {
		int opp = srt[i].second;

		if (!isIncluded(n, opp)) {
			relation[n][opp] = relation[opp][n] = 0;
			continue;
		}

		int ck = false;
		for (int j = idx + 1; j < i; ++j) {
			int thrd = srt[j].second;
			if (isIncluded(n, thrd) && isIncluded(thrd, opp)) {
				relation[n][opp] = relation[opp][n] = 0;
				ck = true;
				break;
			}
		}
		if (!ck) {
			relation[n][opp] = 1;
			relation[opp][n] = 2;
		}
	}
}

int depth(int a)
{
	int maxDepth = 0, secondDepth = 0;
	int len, tmp;

	for (int i = 0; i < N; ++i) {
		if (relation[a][i] == 1) {
			tmp = depth(i);
			if (secondDepth < tmp + 1) {
				secondDepth = min(tmp + 1, maxDepth);
				maxDepth = max(tmp + 1, maxDepth);
			}
		}
	}
	len = maxDepth + secondDepth;
	longest = max(longest, len);
	return maxDepth;
}

int solve()
{
	memset(relation, -1, sizeof(relation));
	longest = 0;
	srt.resize(0);
	for (int i = 0; i < N; ++i) srt.push_back(make_pair(wall[i][2], i));
	sort(srt.begin(), srt.end(), comparePair);

	for (int idx = 0; idx < N - 1; ++idx)
		chkRelation(idx);
	
	depth(0);
	
	int ans = longest;
	return ans;
}

int main()
{
	int T;
	scanf("%d", &T);
	
	while (T--) {

		scanf("%d", &N);
		for (int i = 0; i < N; ++i)
			scanf("%d %d %d", &wall[i][0], &wall[i][1], &wall[i][2]);

		printf("%d\n", solve());
	}
}