#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const int MX = 987654321;
int t, goal, canUse[10];

void input()
{
	for (int i = 0; i < 10; ++i) scanf("%d", &canUse[i]);
	scanf("%d", &goal);
}

bool canMake(int a)
{
	while (a) {
		if (!canUse[a % 10]) return false;
		a /= 10;
	}
	return true;
}

int calcLen(int a)
{
	int len = 0;
	while (a) {
		a /= 10;
		len++;
	}
	return len;
}

int solve(int k)
{
	int ret = MX;
	if (canMake(k)) return calcLen(k);

	for (int i = sqrt(k); i > 1; --i) {
		if (k%i == 0 && canMake(i)) ret = min(ret, 1 + calcLen(i) + solve(k / i));
	}
	
	return ret;
}

int main()
{
	scanf("%d", &t);
	for (int tc = 1; tc <= t; ++tc) {
		input();
		int ans = solve(goal);
		printf("#%d %d\n", tc, ans==MX?-1:ans+1);
	}
}