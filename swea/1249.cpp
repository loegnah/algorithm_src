#include <cstdio>
#include <queue>
#include <utility>
using namespace std;

const int MPLEN = 100;
const int MX = 987654321;
const int STT_Y = 1, STT_X = 1;
const int cy[4] = { 0,1,0,-1 };
const int cx[4] = { 1,0,-1,0 };

int N;
int mp[MPLEN + 3][MPLEN + 3], dst[MPLEN + 3][MPLEN + 3];
priority_queue<pair<int, int> > qu;

void bfs()
{
	int d, y, x, ny, nx, i;

	qu = priority_queue<pair<int, int> >();
	qu.push(make_pair(0, STT_Y * 1000 + STT_X));
	dst[STT_Y][STT_X] = 0;

	while (!qu.empty()) 
	{
		d = -qu.top().first;
		y = qu.top().second / 1000;
		x = qu.top().second % 1000;
		qu.pop();

		for (i = 0; i < 4; ++i) {
			ny = y + cy[i];
			nx = x + cx[i];
			if (ny > 0 && ny <= N && nx > 0 && nx <= N && dst[ny][nx] == -1) {
				dst[ny][nx] = d + mp[ny][nx];
				qu.push(make_pair(-dst[ny][nx], ny * 1000 + nx));
			}
			if (ny == N && nx == N) return;
		}
	}
}

int main()
{
	int T;
	char line[MPLEN + 3];

	scanf("%d", &T);
	for (int TC = 1; TC <= T; ++TC) 
	{
		scanf("%d", &N);
		for (int y = 1; y <= N; ++y) {
			scanf("%s", line);
			for (int x = 1; x <= N; ++x) {
				mp[y][x] = line[x-1] - '0';
				dst[y][x] = -1;
			}
		}

		bfs();
		printf("#%d %d\n", TC, dst[N][N]);
	}
}