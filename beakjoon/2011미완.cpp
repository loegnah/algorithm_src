#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int MOD = 1000000;
string ipt;
int len;
int cache[5002];
const char ZERO = '0', ONE = '1', TWO = '2', SIX = '6';

int dp(int n)
{
  if(n>len) return 0;
  if(n==len) return 1;
  int& ret = cache[n];
  if(ret != -1) return ret;
  ret = 0;
  char cur = ipt[n];
  if(n == len-1) {
    if(cur != ZERO)
      ret += 1;
  }
  else {
    if(ipt[n+1] == ZERO) {
      if(cur == ONE || cur == TWO)
        ret = (ret + dp(n+2)) %MOD;
    }
    else {
      ret = (ret + dp(n+1))%MOD;
      if(cur == ONE) ret = (ret +dp(n+2))%MOD;
      else if(cur == TWO && ipt[n+1]<=SIX) ret = (ret+dp(n+2))%MOD;
    }
  }
  return ret;
}

int main()
{
  cin >> ipt;
  len = ipt.size();
  memset(cache,-1,sizeof cache);
  printf("%d",dp(0));
}
