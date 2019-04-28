#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int A[5001];
int twoSum[400001];
int main(void)
{
	setbuf(stdout, NULL);
	
	int T;
	scanf("%d", &T);
	for (int testcase = 0; testcase < T; ++testcase) {
		int N;
		int ans = 0;
		scanf("%d", &N);
		
		memset(twoSum, 0, sizeof(twoSum));

		for (int i = 0; i < N; ++i) {
			scanf("%d", A + i);
			for (int j = 0; j < i; ++j) {
				if (twoSum[A[i] - A[j] + 200000] == 1) {
					++ans;
					break;
				}
			}
			for (int j = 0; j <= i; ++j)
				twoSum[A[i] + A[j] + 200000] = 1;
		}
		printf("Case #%d\n%d\n", testcase + 1, ans);
	}
}