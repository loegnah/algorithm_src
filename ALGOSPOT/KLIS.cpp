#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
#include <limits>
using namespace std;

const int MAXCT = numeric_limits<int>::max();
int cacheLen[501], cacheCt[501];
int seq[501];
int N, K;
vector<int> ans;


int LIS(int st);
int count_LIS(int st);
void recstrt(int st,int skip);

int main()
{
	int C;

	scanf("%d", &C);
	while (C-- > 0) {
		memset(cacheLen, -1, sizeof(cacheLen));
		memset(cacheCt, -1, sizeof(cacheCt));
		ans.clear();
		scanf("%d %d", &N, &K);

		for (int i = 0; i < N; ++i) scanf("%d", &seq[i]);
		
		recstrt(-1, K - 1);
		printf("%d\n", LIS(-1) - 1);
		for (int i = 0; i < ans.size(); ++i)
			printf("%d ", ans[i]);
		printf("\n");

	}
}

int LIS(int st)
{
	int& ret = cacheLen[st + 1];
	if (ret != -1) return ret;
	ret = 1;
	for (int i = st + 1; i < N; ++i) {
		if (seq[st] < seq[i] || st == -1) ret = max(ret, LIS(i) + 1);
	}
	return ret;
}

int count_LIS(int st)
{
	if (LIS(st) == 1) return 1;

	int &ret = cacheCt[st+1];
	if (ret != -1) return ret;

	ret = 0;
	for (int next = st + 1; next < N; ++next) 
		if ((st == -1 || seq[st] < seq[next]) && (LIS(st) == LIS(next) + 1))
			ret = min<long long>(MAXCT, (long long)ret + count_LIS(next));
	
	return ret;
}

void recstrt(int st, int skip)
{
	if (st != -1) ans.push_back(seq[st]);

	vector<pair<int, int> > follower;
	for (int next = st + 1; next < N; ++next) 
		if ((st == -1 || seq[st] < seq[next]) && (LIS(st) == LIS(next) + 1))
			follower.push_back(make_pair(seq[next], next));
	
	sort(follower.begin(), follower.end());

	for (int i = 0; i < follower.size(); ++i) {
		int index = follower[i].second;
		int cnt = count_LIS(index);

		if (cnt <= skip) skip -= cnt;
		else {
			recstrt(index, skip);
			break;
		}
	}
}