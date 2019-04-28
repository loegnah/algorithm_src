// NPOLY.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;

int cache[101][101];
int N;
int MOD = 20090711;

int poly(int cur, int remain);
int npoly();
int solve();

int main()
{
	int T;
	scanf("%d", &T);
	memset(cache, -1, sizeof(cache));
	while(T--) {
		
		scanf("%d", &N);

		printf("%d\n", solve());
	}
}

int solve()
{
	int ans = 0, npolyAns = 0;
	for (int i = 1; i <= N; ++i)
		ans = (ans + poly(i, N - i)) % MOD;
	npolyAns = npoly();
	ans = (((ans - npolyAns) % MOD) + MOD) % MOD;
	return ans;
}
/*세로 대칭인 경우를 제외하기 위해 반만 잘린 형태의 폴리노미오를 만든다.
이 때 젤 윗줄의 개수만 2씩 증가하면서 만들어주면 됨.
밑에 i==0인 경우는 기존 poly 함수에서 제대로 동작하지 않기 때문에
예외로 처리해준점*/
int npoly()
{
	int ret = 0;
	for (int i = N % 2; N - i >= 0; i += 2) {
		if (i == 0) {
			for (int j = 1; j <= N / 2; ++j)
				ret = (ret + poly(j, (N / 2) - j)) % MOD;
			continue;
		}
		ret += poly(i, (N - i) / 2) % MOD;
	}
	
	return ret;
}

int poly(int cur, int remain)
{
	if (remain == 0) return 1;

	int &ret = cache[cur][remain];
	if (ret != -1) return ret;

	ret = 0;
	for (int next = 1; remain - next >= 0; ++next) {
		ret = ret + (poly(next, remain - next)*(cur + next - 1));
		ret %= MOD;
	}
	return ret;
}