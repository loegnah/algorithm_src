#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int C, R;
string board[21];
int isVisited[26] = { 0 };
int cx[4] = { -1,0,1,0 };
int cy[4] = { 0,1,0,-1 };

int dfs(int y, int x)
{
	if (y < 0 || y >= C || x < 0 || x >= R) return 0;
	if (isVisited[board[y][x] - 'A'] == 1) return 0;
	else isVisited[board[y][x] - 'A'] = 1;
	int ret = -1;
	for (int i = 0; i < 4; ++i) {
		ret = max(ret , dfs(y+cy[i], x+cx[i]));
	}
	isVisited[board[y][x] - 'A'] = 0;
	return ret+1;
}

int main()
{
	cin >> C >> R;
	for (int i = 0; i < C; ++i)
		cin >> board[i];
	cout << dfs(0, 0);
}