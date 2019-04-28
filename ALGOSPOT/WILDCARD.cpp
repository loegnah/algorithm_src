#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<string> strvec;
string wildcard;
int cache[101][101] = {};
int strSize = 0, wildSize = 0;

bool strCheck(string& str,int wN, int sN)
{
	
	int& ret = cache[wN][sN];
	if (ret != -1) return ret;
	
	if (sN < strSize && wN < wildSize && (wildcard[wN] == '?' || wildcard[wN] == str[sN])) {
		return ret = strCheck(str, wN + 1, sN + 1);
	}
	if (wN == wildSize) return ret = (sN == strSize);

	if (wildcard[wN] == '*') {
		if (strCheck(str, wN + 1, sN) || (sN < strSize && strCheck(str, wN, sN + 1))) {
			return ret = 1;
		}
	}
	return ret = 0;
}

int main()
{
	int C, N;

	cin >> C;
	while (C-- > 0) {
		cin >> wildcard;
		cin >> N;
		
		strvec.resize(N);
		wildSize = wildcard.size();
		for (int i = 0; i < N; ++i) cin >> strvec[i];
		sort(strvec.begin(), strvec.end());
		
		for (int i = 0; i < N; ++i) {
			memset(cache, -1, sizeof(cache));
			strSize = strvec[i].size();
			if (strCheck(strvec[i], 0, 0)) cout << strvec[i] << endl;
		}
		strvec.clear();
	}
}