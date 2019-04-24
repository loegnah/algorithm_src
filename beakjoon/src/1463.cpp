#include <iostream>
#include <cstring>
#include <cmath>
#include <limits>
using namespace std;

int cache[1000003] = {};
const int MAX = numeric_limits<int>::max();

int calc(int num)
{
	if(num == 1) return 0;
	
    int& ret = cache[num];
    if(ret != -1) return ret;
    ret = MAX;
    
	if(num%3 ==0) ret = min(ret,1+calc(num/3));
	if(num%2 ==0) ret = min(ret,1+calc(num/2));
	ret = min(ret,1+calc(num-1));

	return cache[num] = ret;
}

int main()
{
	memset(cache,-1,sizeof(cache));
	int n;
	cin >> n;
	cout << calc(n);
}
