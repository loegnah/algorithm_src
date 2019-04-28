#include <iostream>
#include <cstring>
using namespace std;

int table[100][100] = {};
int cache[100][100] = {};
int n;

int JumpGame(int y, int x)
{
	if (x >= n || y >= n) return 0;
	if (x == n - 1 && y == n - 1) return 1;
	int& ret = cache[y][x];
	if (ret != -1) return ret;

	return ret = (JumpGame(y + table[y][x], x) || JumpGame(y, x + table[y][x]));
}

int main()
{
	int C, ret;

	
	cin >> C;
	while (C-- > 0) {
		memset(cache, -1, sizeof(cache));
		cin >> n;
		
		for (int i = 0; i < n; ++i) 
			for (int j = 0; j < n; ++j) scanf("%d", &table[i][j]);
			
		ret = JumpGame(0, 0);
		if (ret) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}