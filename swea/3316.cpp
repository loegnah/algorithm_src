#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int MOD = 1000000007;
const int CASE = 16;
const int MXDAY = 10005;

string str;
int len;
int cache[MXDAY][CASE];

void input_init()
{
	cin >> str;
	len = (int)str.size();
	memset(cache, -1, sizeof cache);
}

int dp(int day, int pre)
{
	if (day == len) return 1;

	int& ret = cache[day][pre];
	if (ret != -1) return ret;
	
	ret = 0;
	for (int i = 0; i < CASE; ++i) {
		if (i & (1 << (str[day] - 'A'))) continue;
		int pp = i | (1 << (str[day] - 'A'));
		if (pp&pre) ret = (ret + dp(day + 1, pp)) % MOD;
	}
	return ret;
}

int main()
{
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		input_init();
		cout << "#" << tc << " " << dp(0, 1) << "\n";
	}
}