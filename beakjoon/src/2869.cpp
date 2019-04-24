#include <cstdio>
using namespace std;

typedef unsigned long long ull;
const ull MX = 1000000005;
ull A, B, V;

int mxHeight(ull day)
{
	ull h = (A*day - B*(day - 1));
	if (h > V) return 1;
	if (h < V) return -1;
	return 0;
}

int main()
{
	scanf("%llu %llu %llu", &A, &B, &V);
	ull hi = MX, lo = 1, mid, count = 200;
	while ((lo <= hi) && count) {
		mid = (hi + lo) / 2;
		int ret = mxHeight(mid);
		if (ret == 1) hi = mid;
		else if (ret == -1) lo = mid+1;
		else break;
		count--;
	}
  printf("%llu",mid);
}
