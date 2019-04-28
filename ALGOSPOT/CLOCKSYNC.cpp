#include <iostream>
using namespace std;

int clockk[16];
const int clockSch[10][5] = {
	{0,1,2,-1,-1},{3,7,9,11,-1},
	{4,10,14,15,-1},{0,4,5,6,7},
	{6,7,8,10,12},{0,2,14,15,-1},
	{3,14,15,-1,-1},{4,5,7,14,15},
	{1,2,3,4,5},{3,4,5,9,13}
};

void PushClock(int schNum) {
	int clockNum, imsiTime;
	for (int i = 0; i < 5; ++i) {
		clockNum = clockSch[schNum][i];
		if (clockNum == -1) break;
		imsiTime = clockk[clockNum] + 3;
		if (imsiTime == 12) clockk[clockNum] = 12;
		else clockk[clockNum] = imsiTime % 12;
	}
}

int ClockSync(int schNum) {
	bool ck = true;
	if (schNum >= 10) {
		for (int i = 0; i < 16; ++i) {
			if (clockk[i] != 12) {
				ck = false;
				continue;
			}
		}
		if (ck) return 0;
		return 987654321;
	}

	int ret = 987654321, imsiret = 0;
	for (int pushN = 0; pushN < 4; ++pushN) {
		imsiret = pushN + ClockSync(schNum + 1);
		ret = ret > imsiret ? imsiret : ret;
		PushClock(schNum);
	}
	return ret;
}

int main()
{
	int C, ans;
	cin >> C;
	while (C-- > 0) {
		for (int i = 0; i < 16; ++i) scanf("%d", &clockk[i]);
		ans = ClockSync(0);
		if (ans > 2000000) cout << "-1" << endl;
		else cout << ans << endl;
	}
}