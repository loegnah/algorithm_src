#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int cache[101][10001] = {};
int n,k = 0;
vector<int> coin = {};
int CoinFunc(int cur,int sum)
{
	if(cur > n-1 || sum > k) return -100000;
	if(sum == k) return 0;
	if(cache[cur][sum] != -1) return cache[cur][sum];
	
	int a = 1+CoinFunc(cur,sum+coin[cur]);
	int b = CoinFunc(cur+1,sum);
	if(a<0 || b<0) {
		if(a>0) return cache[cur][sum] = a;
		if(b>0) return cache[cur][sum] = b;
		return cache[cur][sum] = -100000;	
	}
	return cache[cur][sum] = min(a,b);	
}

int main()
{
	int imsi;
	memset(cache, -1, sizeof(cache));
	scanf("%d %d", &n, &k);
	coin.reserve(n);
	
	for (int i=0; i < n; ++i) {
		scanf("%d", &imsi);
		coin.push_back(imsi);
	}
	int ret = CoinFunc(0,0);
	if(ret<0) printf("-1");
	else printf("%d",ret);
}
