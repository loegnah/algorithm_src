#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstring>
using namespace std;

int N, S;
int cache[102][12];
int INF = 1000000000;
int arr[101], totSum[101], totSqSum[101];

void setting();
int quantization(int st, int rest);
int variance(int st, int en);


int main()
{
	int C,tmp;
	
	
	scanf("%d", &C);
	arr[0] = totSum[0] = totSqSum[0] = 0;

	for (int i = 0; i < C; ++i) {
		memset(cache, -1, sizeof(cache));
		scanf("%d %d", &N, &S);
		for (int j = 1; j <= N; ++j) 
			scanf("%d", arr+j);
		
		setting();
		printf("%d\n", quantization(1, S));
	}
}

void setting()
{
	sort(arr+1, arr+N+1);
	for (int i = 1; i <= N; ++i) {
		totSum[i] = totSum[i - 1] + arr[i];
		totSqSum[i] = totSqSum[i - 1] + arr[i] * arr[i];
	}
}

int quantization(int st, int rest)
{
	if (st > N) return 0;
	if (rest == 0) return INF;

	int &ret = cache[st][rest];
	if (ret != -1) return ret;

	ret = INF;

	for (int size = 1; st + size <= N+1; ++size) {
		ret = min(ret, variance(st, st + size - 1) + quantization(st + size, rest - 1));
	}
	return ret;
}

int variance(int st, int en)
{
	int sum = totSum[en] - totSum[st - 1];
	int sqSum = totSqSum[en] - totSqSum[st - 1];
	int avg = int(0.5+ (double)sum / (en - st + 1));
	int ret = sqSum - 2 * avg*sum + avg*avg*(en - st + 1);
	return ret;
}