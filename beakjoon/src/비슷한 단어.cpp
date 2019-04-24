#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
	string baseStr,testStr;
	int n, ans=0;
	int diff, changeCount, ck;
	int baseArr[26] = {};
	int testArr[26] = {};
	
	cin >> n;
	cin >> baseStr;
	
	for(int i=0; i<baseStr.length(); ++i) {
		baseArr[baseStr[i]-0x41] += 1;
	}
	
	for(int i=0; i<n-1; ++i) {
		memset(testArr,0,sizeof(testArr));
		ck = 0;
		changeCount = 0;
		cin >> testStr;
		for(int k=0; k<testStr.length(); ++k) testArr[testStr[k]-0x41] += 1;
		for(int t=0; t<26; ++t) {
			diff = baseArr[t] - testArr[t];
			if(diff == 0) continue;
			ck += diff;
			changeCount++;
		}
		if(ck==0 && changeCount<=2 || abs(ck)==1 && changeCount==1) ans++;
	}
	cout << ans; 
}
