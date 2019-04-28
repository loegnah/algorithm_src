#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int cache[10005] = {};
string str;

int Level(int st, int len)
{
	bool isSameStr = true;
	for (int i = st + 1; i < st + len; ++i) {
		if (str[st] != str[i]) {
			isSameStr = false;
			break;
		}
	}
	if (isSameStr) return 1;

	bool isProgressive = true;
	for (int i = st + 1; i < st + len - 1; ++i) {
		if (str[i] - str[i - 1] != str[i+1] - str[i]) {
			isProgressive = false;
			break;
		}
	}
	if (isProgressive && abs(str[st]-str[st+1])==1) return 2;

	bool isAlternate = true;
	for (int i = st; i < st + len - 2; ++i) {
		if (str[i] != str[i+2]) {
			isAlternate = false;
			break;
		}
	}
	if (isAlternate) return 4;
	if (isProgressive) return 5;
	return 10;
}

int PI(int st)
{
	if (str.size() == st) return 0;
	int& ans = cache[st];
	if (ans != -1) return ans;

	ans = 987654321;
	for (int i = 3; i <= 5; ++i) {
		if (str.size() - st >= i) ans = min(ans, (Level(st, i) + PI(st + i)));
	}
	return ans;
}

int main()
{
	int C;
	str.resize(10001);

	cin >> C;
	while (C-- > 0) {
		memset(cache, -1, sizeof(cache));
		cin >> str;
		cout << PI(0) << endl;
	}
}