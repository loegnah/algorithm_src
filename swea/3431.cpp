#include <cstdio>
using namespace std;

int main()
{
	int t,a,b,c;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; ++tc) {
		scanf("%d %d %d", &a, &b, &c);
		printf("#%d %d\n", tc, (c > b) ? -1 : ((c > a) ? 0 : a - c));
	}
}
