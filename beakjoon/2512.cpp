#include <cstdio>
#include <algorithm>
using namespace std;

const int MX = 1000000005;
int N,M,s=0;
int arr[10005];;

int isOk(int mxMoney)
{
	int sum = 0;
	for (int i = 0; i < N; ++i) {
		if (arr[i] >= mxMoney) {
			sum += mxMoney*(N - i);
			break;
		}
		sum += arr[i];
	}
	if (sum > M) return 1;
	if (sum < M) return -1;
	return 0;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", arr + i);
		s += arr[i];
	}
	sort(arr, arr + N);
	scanf("%d", &M);

	if (s <= M) {
		printf("%d", arr[N - 1]);
		return 0;
	}
	int hi = MX, lo = 0, mid, ret, count = 100;
	while ((lo < hi) && count) {
		mid = (lo + hi) / 2;
		ret = isOk(mid);

		if (ret == 1) hi = mid;
		else if (ret == -1) lo = mid;
		else break;
		count--;
	}
	printf("%d\n", mid);
}