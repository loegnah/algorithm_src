#include <cstdio>
#include <string>
using namespace std;

const int MX_N = 1000003;
const char YES = '1';
const char NO = '0';

int n, m, a, b, comd;
int parent[MX_N];
string ans;

void init()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) parent[i] = i;
	ans = "";
}

int getParent(int k)
{
	if (k == parent[k]) return k;
	return parent[k] = getParent(parent[k]);
}

char isSameSet(int a, int b)
{
	if (getParent(a) == getParent(b)) return YES;
	return NO;
}

void mergeSet(int a, int b)
{
	if (getParent(a) == getParent(b)) return;
	parent[getParent(a)] = getParent(b);
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {	
		init();

		for (int i = 0; i < m; ++i) {
			scanf("%d %d %d", &comd, &a, &b);
			if (comd) ans.push_back(isSameSet(a,b));
			else mergeSet(a, b);
		}
		printf("#%d %s\n", tc, ans.c_str());
		
	}
}