#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int cache[501];
int seq[500];
int N;

int LIS(int st)
{
	int& ret = cache[st+1];
	if (ret != -1) return ret;
	ret = 1;
	for (int i = st + 1; i < N; ++i) {
		if (seq[st] < seq[i] || st == -1) ret = max(ret, LIS(i) + 1);
	}
	return ret;
}

int main()
{
	int C;
	
	cin >> C;
	while (C-- > 0) {
		memset(cache, -1, sizeof(cache));
		cin >> N;

		for (int i = 0; i < N; ++i) scanf("%d", &seq[i]);
		cout << LIS(-1)-1 << endl;
	}
}