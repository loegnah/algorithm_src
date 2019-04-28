#include <iostream>
#include <string>
#include <vector>
using namespace std;


vector<int> selfKMP(const string n)
{
	int m = n.size();
	int begin = 1, matched = 0;
	vector<int> pi(m, 0);

	while (begin + matched < m) {
		if (n[begin + matched] == n[matched]) {
			++matched;
			pi[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0)
				++begin;
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pi;
}

int moveDial(const string h, const string n)
{
	vector<int> pi = selfKMP(n);
	int begin = 0, matched = 0;
	
	int hs = h.size(), ns = n.size();
	while (begin <= hs - ns) {
		if (matched < ns && h[begin + matched] == n[matched]) {
			++matched;
			if (matched == ns) return begin;
		}
		else {
			if (matched == 0)
				++begin;
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	printf("error error error!!!!!\n");
	exit(0);
}

void solve()
{
	int moveCt = 0;
	string ini, next;
	int N;

	scanf("%d", &N);
	
	cin >> ini;
	for (int i = 0; i < N; ++i) {
		cin >> next;
		
		if (i % 2 != 0) moveCt += moveDial(ini + ini, next);
		else moveCt += moveDial(next + next, ini);
		
		ini = next;
	}
	printf("%d\n", moveCt);
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc) {
		solve();
	}
}