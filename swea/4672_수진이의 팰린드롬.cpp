#include <cstdio>
#include <cstring>
using namespace std;

const char A = 'a';
const char Z = 'z';

int preSum[12];
char ipt[12];

void pre_calc()
{
	preSum[0] = 0;
	for (int i = 1; i <= 10; ++i) 
		preSum[i] = preSum[i - 1] + i;
}

int main()
{
	int T;
	
	scanf("%d", &T);
	pre_calc();

	for (int tc = 1; tc <= T; ++tc) {
		int count[30] = { 0 };
		int ans = 0;

		scanf("%s", ipt);
		for (int i = 0; i < strlen(ipt); ++i) count[ipt[i] - A]++;
		for (int i = 0; i <= Z - A; ++i) ans += preSum[count[i]];
		printf("#%d %d\n", tc, ans);
	}
}