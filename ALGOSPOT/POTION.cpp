#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
int R[1001], P[1001], ans[1001];

int gcd(int a, int b)
{
	if (b > a)
		swap(a, b);
	while (b != 0) {
		a = a % b;
		swap(a, b);
	}
	return a;
}

bool baseCase()
{
	bool ck = false;
	for (int i = 0; i < N; ++i) 
		if (P[i] >= R[i]) {
			ck = true;
			break;
		}
	
	if (!ck) {
		for (int i = 0; i < N; ++i)
			ans[i] = R[i] - P[i];
	}
	return ck;
}

void solve()
{
	int a, b;
	double potion;
	
	if (!baseCase())
		return;

	b = R[0];
	for (int i = 1; i < N; ++i)
		b = gcd(b, R[i]);

	potion = 0;
	for (int i = 0; i < N; ++i)
		potion = max(potion, (double)P[i] / R[i]);
	
	a = ceil(potion*b);
	
	for (int i = 0; i < N; ++i) {
		ans[i] = R[i] * a / b - P[i];
	}
}

int main()
{
	int T;

	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++i)
			scanf("%d", R + i);
		for (int i = 0; i < N; ++i)
			scanf("%d", P + i);
		solve();
		for (int i = 0; i < N; ++i)
			printf("%d ", ans[i]);
		printf("\n");
	}
}