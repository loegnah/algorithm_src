#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M, A[1005], B[1005], ct[1005];

int main()
{
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		scanf("%d %d", &N, &M);
		for (int i = 0; i < N; ++i) scanf("%d", A + i);
		for (int i = 0; i < M; ++i) scanf("%d", B + i);
		memset(ct, 0, sizeof ct);

		sort(B, B + M);
		for (int i = 0, j = M - 1; j >= 0; --j) {
			while (B[j] < A[i]) ++i;
			ct[i]++;
		}

		int mx = 0, mxidx = 0;
		for(int i=0; i<N; ++i)
			if (mx < ct[i]) {
				mx = ct[i];
				mxidx = i;
			}
		printf("#%d %d\n", tc, mxidx+1);
	}
}