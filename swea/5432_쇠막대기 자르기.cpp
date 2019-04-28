#include <cstdio>
#include <cstring>
using namespace std;

const char OPEN = '(';
const char CLOSE = ')';

char ipt[100005];
int count;

int main()
{
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		scanf("%s", ipt);
		int iptLen = strlen(ipt);
		int ans = 0;

		for (int i = 0; i < iptLen; ++i) {
			if (ipt[i] == OPEN) count++;
			else if (ipt[i - 1] == OPEN) ans += (--count);
			else {
				ans++;
				count--;
			}
		}

		printf("#%d %d\n", tc, ans);
	}
}