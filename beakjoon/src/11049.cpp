#include <cstdio>
#include <cstring>
#include <algorithm>
#include <limits>
using namespace std;

const int MX = numeric_limits<int>::max();
int n,arr[503][2],cache[503][503];

int aib(int a,int i,int b)
{
  return arr[a][0]*arr[i][1]*arr[b][1];
}

int dp(int a,int b)
{
  if(a==b) return 0;
  if(a==b-1) return aib(a,a,b);
  int& ret = cache[a][b];
  if(ret != -1) return ret;
  ret = MX;
  for(int i=a; i<b; ++i) ret = min(ret,dp(a,i)+dp(i+1,b)+aib(a,i,b));
  return ret;
}

int main()
{
  scanf("%d",&n);
  for(int i=1; i<=n; ++i) scanf("%d %d",&arr[i][0],&arr[i][1]);
  memset(cache, -1, sizeof cache);
  printf("%d\n",dp(1,n));
}
