#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int CX[4] = { 0,0,-1,1 }, CY[4] = { 1,-1,0,0 };
const int SIZE = 2000;
const int MID = 1000;

struct atom {
	int y, x, dir, energ;
	atom() { y = x = dir = energ = 0; }
	atom(int _y, int _x, int _dir, int _k)
		:y(_y), x(_x), dir(_dir), energ(_k) {}
};

int N, board[SIZE+3][SIZE+3];
int aliveCount, ans;
vector<atom> atoms;
vector<int> willMove, boomY, boomX;
vector<bool> isAlive;

void input_init()
{
	int x, y, dir, energ;

	memset(board, 0, sizeof(board));

	scanf("%d", &N);
	aliveCount = N;
	isAlive = vector<bool>(N+1,true);

	atoms = vector<atom>();
	atoms.push_back(atom());
	for (int idx = 1; idx <= N; ++idx) {
		scanf("%d %d %d %d", &x, &y, &dir, &energ);
		atoms.push_back(atom(y + MID, x + MID, dir, energ));
		board[y + MID][x + MID] = idx;
	}
}

bool collisionCheck(int idx1, int idx2)
{
	if (atoms[idx1].dir / 2 == atoms[idx2].dir / 2 &&
		atoms[idx1].dir != atoms[idx2].dir) return true;
	return false;
}


// 원자 충돌 처리
void boom_atom(int idx)
{
	ans += atoms[idx].energ;
	isAlive[idx] = false;
	aliveCount--;
}

// 원자 이동
void move_atom(int idx, int ny, int nx)
{
	board[atoms[idx].y][atoms[idx].x] = 0;

	if (ny<0 || nx<0 || ny>SIZE || nx>SIZE) {
		isAlive[idx] = false;
		return;
	}

	int& next = board[ny][nx];
	if (next > 0 && collisionCheck(idx, next)) {
		boom_atom(idx);
		boom_atom(next);
		next = 0;
		return;
	}

	atoms[idx].y = ny;
	atoms[idx].x = nx;
	willMove.push_back(idx);
}
// 디버그용
void printBoard()
{
	printf("\n");
	for (int y = 1990; y < 2010; ++y) {
		for (int x = 1990; x < 2010; ++x) printf("%d ", board[y][x]);
		printf("\n");
	}
}

void solve()
{
	int nx = 0, ny = 0, y = 0, x = 0;
	ans = 0;

	// 각 시간 1초마다 처리
	for (int tm = 0; (tm < SIZE) && (aliveCount > 1); ++tm) {
		//printBoard();
		willMove.clear();
		boomY.clear();
		boomX.clear();

		// 원자들 각각 무브 (서로 중간에 충돌하는 것만 선처리)
		for (int idx = 1; idx <= N; ++idx) {
			if (!isAlive[idx]) continue;

			ny = atoms[idx].y + CY[atoms[idx].dir];
			nx = atoms[idx].x + CX[atoms[idx].dir];
			move_atom(idx, ny, nx);
		}
		
		// 중간 충돌 안하는 것들 옮겨서 충돌확인
		for (int idx : willMove) {
			y = atoms[idx].y;
			x = atoms[idx].x;

			// 아무것도 없을 때 그냥 옮김
			if (board[y][x] == 0) board[y][x] = idx;
			// 다른 원자도 이곳으로 올 때 (충돌)
			else if (board[y][x] > 0) {
				boom_atom(idx); 
				boom_atom(board[y][x]);

				board[y][x] = -1;
				boomY.push_back(y); // 다음 턴되기전에 -1 표시 지워야됨
				boomX.push_back(x);
			}
			// 이미 충돌했는 곳 (board[y][x] == -1)
			else boom_atom(idx);
		}
		for (int i = 0; i < boomY.size(); ++i) {
			board[boomY[i]][boomX[i]] = 0;
		}
	}
}

int main()
{
	int T;
	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		input_init();
		solve();
		printf("#%d %d\n", tc, ans);
	}
}