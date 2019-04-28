#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int ZERO = (int)'0';
int T;
string str2, str3;

int convert_to_digit(string& s, int k)
{
	int t = 1, dgt = 0;
	for (int i = (int)s.size()-1; i >= 0; --i) {
		dgt += (s[i] - ZERO)*t;
		t *= k;
	}
	return dgt;
}

string convert_to_third(int digit)
{
	string ret = "";
	
	while (digit) {
		ret.push_back((char)(digit % 3 + '0'));
		digit /= 3;
	}

	reverse(ret.begin(), ret.end());
	return ret;
}

int solve()
{
	string s2;
	for (int i = 0; i < str2.size(); ++i) {
		s2 = str2;
		s2[i] = '1' - s2[i] + '0';

		int dgt = convert_to_digit(s2, 2);
		string cvt_str3 = convert_to_third(dgt);

		int cnt = 0;
		for (int j = 0; j < cvt_str3.size(); ++j) {
			if (cvt_str3[j] != str3[j]) cnt++;
			if (cnt > 1) break;
		}
		if (cnt == 1) return dgt;
	}
	return -1;
}

int main()
{
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		cin >> str2;
		cin >> str3;
		cout << "#" << tc << " " << solve() << "\n";
	}
}