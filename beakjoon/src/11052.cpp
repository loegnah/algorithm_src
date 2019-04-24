#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,p[1002];
int cache[1002][1002];

int dp(int cur, int rmn)
{
  if((cur == n) || (rmn <= 0)) return 0;
  int& ret = cache[cur][rmn];
  if(ret != -1) return ret;

  ret = dp(cur+1,rmn);
  if(rmn > cur) ret = max(ret,dp(cur,rmn-cur-1)+p[cur]);
  return ret;
}

int main()
{
  memset(cache, -1, sizeof cache);
  scanf("%d",&n);
  for(int i=0; i<n; ++i) scanf("%d",p+i);
  printf("%d",dp(0,n));
}
