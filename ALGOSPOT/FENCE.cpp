#include <iostream>
#include <algorithm>
using namespace std;

int fenceHigh[20000] = {};

int Fence(int left, int right)
{
	if (left == right) return fenceHigh[left];

	int mid = (left + right) / 2;
	int ret = max(Fence(left, mid), Fence(mid + 1, right));

	int lo = mid, hi = mid + 1;
	int High = min(fenceHigh[lo], fenceHigh[hi]);
	ret = max(ret, High * 2);

	while (left < lo || hi < right) {
		if ((hi < right) && ((lo == left) || (fenceHigh[lo - 1] < fenceHigh[hi + 1]))) {
			++hi;
			High = min(High, fenceHigh[hi]);
		}
		else {
			--lo;
			High = min(High, fenceHigh[lo]);
		}
		ret = max(ret, High*(hi - lo + 1));
	}
	return ret;
}

int main()
{
	int C, N, ret;
	scanf("%d", &C);

	while (C-- > 0) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++i) scanf("%d", &fenceHigh[i]);

		ret = Fence(0, N - 1);
		printf("%d\n", ret);
	}
}