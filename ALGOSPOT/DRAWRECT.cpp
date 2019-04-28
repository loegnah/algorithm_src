// NPOLY.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int solve(int x[])
{
	if (x[0] == x[1]) return x[2];
	if (x[1] == x[2]) return x[0];
	return x[1];
}

int main()
{
	int T;
	scanf("%d", &T);
	
	int a[3], b[3];
	while (T--) {
		for (int i = 0; i < 3; ++i)
			scanf("%d %d", a + i, b + i);
		
		printf("%d %d\n",solve(a),solve(b));
	}
}