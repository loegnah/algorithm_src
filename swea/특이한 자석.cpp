#include <cstdio>
using namespace std;

const unsigned int LF = 1 << 1;
const unsigned int RT = 1 << 5;
const unsigned int MG = (1 << 8) - 1;
const unsigned int FR = 1 << 7;
const unsigned int EN = 1;


int K;
unsigned int state[4];

void input_init()
{
	int ipt;
	scanf("%d", &K);
	for (int i = 0; i < 4; ++i) {
		state[i] = 0;
		for (int j = 0; j < 8; ++j) {
			state[i] <<= 1;
			scanf("%d", &ipt);
			state[i] |= ipt;
		}
	}
}

void rotateMag(int mgn, int dir, int pre)
{
	// 오른쪽 체크
	if (mgn < 3 && pre != 1 && (((state[mgn] & RT) >> 5) != ((state[mgn + 1] & LF) >> 1))) {
		unsigned int a =((state[mgn]));
		unsigned int b = ((state[mgn + 1]));
		rotateMag(mgn + 1, -dir, -1);
	}
	// 왼쪽 체크
	if (mgn > 0 && pre != -1 && (((state[mgn] & LF) >> 1) != ((state[mgn - 1] & RT) >> 5)))
		rotateMag(mgn - 1, -dir, 1);
	
	// 반시계
	if (dir == -1) {
		unsigned int tmp = (state[mgn] & FR);
		state[mgn] <<= 1;
		if (tmp) state[mgn] += 1;
		state[mgn] &= MG;
	}
	// 시계
	else {
		unsigned int tmp = (state[mgn] & EN);
		state[mgn] >>= 1;
		state[mgn] |= (tmp << 7);
	}
}

int solve()
{
	int magNum, dir;
	for(int i=0; i<K; ++i) {
		scanf("%d %d", &magNum, &dir);
		rotateMag(magNum-1, dir, 0);
	}

	int score = 0, sc = 1;
	for (int i = 0; i < 4; ++i) {
		if (state[i] & FR) score += sc;
		sc *= 2;
	}

	return score;
}

int main()
{
	int T;
	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (int tc = 1; tc <= T; ++tc) {
		input_init();
		printf("#%d %d\n", tc, solve());
	}
}