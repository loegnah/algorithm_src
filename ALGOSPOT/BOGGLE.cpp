#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

vector<string> baseStr(5);
string findStr;
int dx[] = { -1,0,1,1,1,0,-1,-1 };
int dy[] = { -1,-1,-1,0,1,1,1,0 };
int cache[5][5][10] = {};

bool Boggle(int y, int x, int strN)
{
	if (y > 4 || y < 0 || x>4 || x < 0) return false;
	if (findStr[strN] != baseStr[y][x]) return false;
	if (findStr.size() == strN + 1) return true;
	if (cache[y][x][strN] != -1) return cache[y][x][strN];

	for (int i = 0; i < 8; ++i) {
		if (Boggle(y + dy[i], x + dx[i], strN + 1)) return cache[y][x][strN] = true;
	}
	return cache[y][x][strN] = false;
}

int main()
{
	int C, N;
	bool ret;

	cin >> C;

	for (int i = 0; i < C; ++i) {
		for (int j = 0; j < 5; ++j) cin >> baseStr[j];
		cin >> N;
		for (int j = 0; j < N; ++j) {
			cin >> findStr;

			memset(cache, -1, sizeof(cache));
			ret = false;
			for (int a = 0; a < 5; ++a) {
				for (int b = 0; b < 5; ++b) {
					if (Boggle(a, b, 0)) {
						ret = true;
						break;
					}
				}
			}
			cout << findStr;
			if (ret) cout << " YES" << endl;
			else cout << " NO" << endl;
		}
	}
}