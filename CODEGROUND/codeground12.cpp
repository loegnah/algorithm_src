#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int N;
int mir[1001][1001];
bool isVisited[1001][1001];

int solve()
{
	int x = 0, y = 0, preX, preY;
	int drc = 0; // West : 0, N : 1 , E : 2, S : 3
	int curMir, varX = 1, varY = 0;
	int totVisitMir = 0;

	memset(isVisited, 0, sizeof(isVisited));
	do {
		curMir = mir[y][x];
		preX = x;
		preY = y;
		if(curMir == 0) {
			// drc = drc
			x = x + varX;
			y = y + varY;
		}
		else {
			if (!isVisited[y][x]) {
				isVisited[y][x] = true;
				totVisitMir++;
			}
			if (curMir == 1) {
				if (drc == 0) drc = 3;
				else if (drc == 1) drc = 2;
				else if (drc == 2) drc = 1;
				else drc = 0;
				x = x + (-1)*varY;
				y = y + (-1)*varX;
			}
			else if (curMir == 2) {
				if (drc == 0) drc = 1;
				else if (drc == 1) drc = 0;
				else if (drc == 2) drc = 3;
				else drc = 2;
				x = x + varY;
				y = y + varX;
			}
		}
		varX = x - preX;
		varY = y - preY;
	} while (x >= 0 && x < N && y >= 0 && y < N);

	return totVisitMir;
}

int main()
{
	int T;
	string ipt;

	setbuf(stdout, NULL);
	scanf("%d", &T);
	
	for (int tc = 1; tc <= T; ++tc) {
		scanf("%d", &N);
		for (int y = 0; y < N; ++y) {
			cin >> ipt;
			for (int x = 0; x < N; ++x)
				mir[y][x] = ipt[x] - '0';
		}
		printf("Case #%d\n", tc);
		printf("%d\n", solve());
	}
}