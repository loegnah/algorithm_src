#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

const int V = 8;
const int VV = 64;
const int dy[2] = { 1,1 };
const int dx[2] = { -1,1 };

int N;
vector<string> board;
int id[2][V][V];
int n, m;
int adj[VV][VV];
vector<int> aMatch, bMatch;
vector<bool> isVisited;

void input() {
	cin >> N;
	board.clear();

	string inStr;
	for (int i = 0; i < N; ++i) {
		cin >> inStr;
		board.push_back(inStr);
	}
}

void dsgId() {
	memset(id, -1, sizeof(id));
	int count[2] = { 0,0 };

	for (int dir = 0; dir < 2; ++dir)
		for (int y = 0; y < N; ++y)
			for (int x = 0; x < N; ++x)
				if (board[y][x] == '.' && id[dir][y][x] == -1) {
					int cy = y;
					int cx = x;
					while (0 <= cy && cy < N && 
						0 <= cx && cx < N && 
						board[cy][cx] == '.') {
						id[dir][cy][cx] = count[dir];
						cy += dy[dir];
						cx += dx[dir];
					}
					count[dir] += 1;
				}
	n = count[0];
	m = count[1];
}

void connect() {
	memset(adj, 0, sizeof(adj));
	for (int y = 0; y<N; ++y)
		for (int x = 0; x < N; ++x)
			if (board[y][x] == '.')
				adj[id[0][y][x]][id[1][y][x]] = 1;
}

bool dfs(int a) {
	if (isVisited[a]) return false;
	isVisited[a] = true;
	
	for (int b = 0; b < m; ++b) 
		if (adj[a][b])
			if (bMatch[b] == -1 || dfs(bMatch[b])) {
				aMatch[a] = b;
				bMatch[b] = a;
				return true;
			}
	return false;
}

int biPartMatch() {
	aMatch = vector<int>(n, -1);
	bMatch = vector<int>(m, -1);

	int size = 0;
	for (int st = 0; st < n; ++st) {
		isVisited = vector<bool>(n, false);
		if (dfs(st))
			++size;
	}
	return size;
}
int solve() {

	dsgId();
	connect();
	return biPartMatch();
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		input();
		printf("%d\n",solve());
	}
}