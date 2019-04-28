#include <iostream>
#include <algorithm>
using namespace std;

int N, M, prf[21], price[21], maxPrf[201];

int main()
{
	int C, tmp, don, ret;

	scanf("%d", &C);
	for (int c = 0; c < C; ++c) {
		ret = 0;
		scanf("%d %d", &N, &M);
		M /= 100;

		for (int n = 0; n < N; ++n) {
			scanf("%d %d", &tmp, prf + n);
			price[n] = tmp / 100;
		}

		for (int m = 0; m <= M; ++m) {
			don = 0;
			for (int n = 0; n < N; ++n)
				if(m >= price[n])
					don = max(don, maxPrf[(m - price[n]) % 201] + prf[n]);
			maxPrf[m % 201] = don;
			ret = max(ret, don);	
		}
		printf("%d\n", ret);
	}
}