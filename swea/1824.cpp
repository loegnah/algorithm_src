#include <cstdio>
#include <cstring>
using namespace std;

const char ANS[2][4] = { "NO","YES" };
const int MAX_STACK = 20 * 20 * 16;
const int cy[5] = { 0,1,0,-1,0 };
const int cx[5] = { 0,0,1,0,-1 };
const int MOD = 16;

int R, C, proc[128], stc[MAX_STACK][2], top;
bool ans, isVisit[20][20][16][5];
char cmd[21][21];

void init()
{
	proc['v'] = 1; proc['>'] = 2;
	proc['^'] = 3; proc['<'] = 4;
	proc['_'] = proc['|'] = proc['?'] = proc['.'] = proc['+'] = proc['-'] = 0;
}

bool solve(int y, int x, int mem, int drc)
{
	char cur = cmd[y][x];
	if (cur == '@') return true;

	bool &iv = isVisit[y][x][mem][drc];
	if (iv) return false;
	iv = true;

	if (cur == '?') {
		for (int i = 1; i <= 4; ++i)
			if (solve((y + cy[i] + R) % R, (x + cx[i] + C) % C, mem, i))
				return true;
	}

	if (proc[cur]) drc = proc[cur];
	else if (cur == '_') drc = (mem == 0 ? 2 : 4);
	else if (cur == '|') drc = (mem == 0 ? 1 : 3);
	else if ('0' <= cur && cur <= '9') mem = cur - '0';
	else if (cur == '+') mem = (mem + 1) % MOD;
	else if (cur == '-') mem = (mem + MOD - 1) % MOD;

	return solve((y + cy[drc] + R) % R, (x + cx[drc] + C) % C, mem, drc);
}

int main()
{
	int t;
	scanf("%d", &t);
	init();
	for (int tc = 1; tc <= t; ++tc) {
		scanf("%d %d", &R, &C);
		for (int i = 0; i < R; ++i) scanf("%s", cmd[i]);

		memset(isVisit, 0, sizeof isVisit);

		bool ck = false;
		for(int y=0; !ck && y<R; ++y) for(int x=0; x<C; ++x)
			if (cmd[y][x] == '@') {
				ck = true;
				break;
			}

		if (!ck) ans = false;
		else ans = solve(0, 0, 0, 2);
		printf("#%d %s\n", tc, ANS[ans]);
	}
}
