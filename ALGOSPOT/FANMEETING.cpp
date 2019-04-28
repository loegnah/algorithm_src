// FANMEETING.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include <iostream>
#include <string>
#include <bitset>
using namespace std;



int solve()
{
	string mem, fan;
	cin >> mem;
	cin >> fan;

	int memLen = mem.length(), fanLen = fan.length();

	for (int i = 0; i < memLen; ++i)
		mem[i] = (mem[i] == 'F') ? '0' : '1';
	for (int i = 0; i < fanLen; ++i)
		fan[i] = (fan[i] == 'F') ? '0' : '1';

	bitset< 200000 > memb(mem);
	bitset< 200000 > fanb(fan);
	int ans = 0;
	for (int i = 0; i < fanLen - memLen +1; ++i) {
		if ((memb & fanb) == 0) ++ans;
		fanb = (fanb >> 1);
	}

	return ans;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		printf("%d\n", solve());
	}
}

