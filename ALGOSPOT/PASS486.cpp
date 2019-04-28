#include <iostream>
#include <cmath>
using namespace std;

const int MAXNUM = 10000001;

int N, LO, HI;
int factorCt[MAXNUM], minFactor[MAXNUM], minFacCt[MAXNUM];

void initialFunc()
{
	for (int i = 0; i < MAXNUM; ++i)
		minFactor[i] = i;

	int sqrti = int(sqrt(MAXNUM));
	for (int i = 2; i <= sqrti; ++i)
		if (minFactor[i] == i)
			for (int j = i*i; j < MAXNUM; j += i)
				if(minFactor[j] == j)
					minFactor[j] = i;
	
	factorCt[1] = 1;
	int k;
	for (int i = 2; i < MAXNUM; ++i) {
		if (minFactor[i] == i) {
			minFacCt[i] = 1;
			factorCt[i] = 2;
		}
		else {
			k = i / minFactor[i];
			if (minFactor[i] != minFactor[k])
				minFacCt[i] = 1;
			else 
				minFacCt[i] = minFacCt[k] + 1;
			factorCt[i] = (factorCt[k] / minFacCt[i]) * (minFacCt[i] + 1);
		}
	}
}

int solve()
{
	int ans = 0;
	for (int i = LO; i <= HI; ++i)
		if (factorCt[i] == N)
			++ans;
	return ans;
}

int main()
{
	initialFunc();

	int T;
	scanf("%d", &T);
	for (int tc = 0; tc < T; ++tc) {
		scanf("%d %d %d", &N, &LO, &HI);
		printf("%d\n", solve());
	}
}