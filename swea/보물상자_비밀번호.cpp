#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int chToInt(char ch)
{
	if (ch <= '9') return ch - '0';
	return (ch - 'A') + 10;
}

int main()
{
	int T,N,K;
	vector<int>	v;
	string s;

	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		v.clear();
		cin >> N >> K;
		cin >> s;

		int numLen = N / 4;
		int p = pow(16, numLen - 1);
		for (int i = 0; i < numLen - 1; ++i) s.push_back(s[i]);
		for (int i = 0; i < N; ++i) {
			int wgt = p, num = 0;
			for (int j = 0; j < numLen; ++j) {
				num += chToInt(s[i + j])*wgt;
				wgt /= 16;
			}
			v.push_back(-num);
		}

		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		printf("#%d %d\n", tc, -v[K - 1]);
	}
}