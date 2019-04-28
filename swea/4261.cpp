#include <iostream>
#include <vector>
#include <string>
using namespace std;

int T, N;
char number['z' + 1];
unsigned int S_len;
string S, voca;

void pre_proc()
{
	number['a'] = number['b'] = number['c'] = '2';
	number['d'] = number['e'] = number['f'] = '3';
	number['g'] = number['h'] = number['i'] = '4';
	number['j'] = number['k'] = number['l'] = '5';
	number['m'] = number['n'] = number['o'] = '6';
	number['p'] = number['q'] = number['r'] = number['s'] = '7';
	number['t'] = number['u'] = number['v'] = '8';
	number['w'] = number['x'] = number['y'] = number['z'] = '9';
}

void input_init()
{
	cin >> S >> N;
	S_len = S.size();
	voca.resize(N);
}

int solve()
{
	int ret = 0;

	for (int v = 0; v < N; ++v) {
		cin >> voca;

		if (voca.size() != S_len) continue;
		bool ck = true;
		for (int i = 0; i < S_len; ++i) {
			if (S[i] != number[voca[i]]) {
				ck = false;
				break;
			}
		}
		if (ck) ret++;
	}
	return ret;
}

int main()
{
	pre_proc();
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		input_init();
		int ans = solve();
		printf("#%d %d\n", tc, ans);
	}
}