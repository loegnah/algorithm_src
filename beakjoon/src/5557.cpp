#include <cstdio>
#include <cstring>
using namespace std;

int n, arr[103];
long long dp[2][21];

int main()
{
  int a,cur,pre,i,j;
  scanf("%d",&n);
  for(i=0; i<n; ++i) scanf("%d",arr+i);
  for(i=0; i<=20; ++i) dp[0][i] = 0;
  dp[0][arr[0]] = 1LL;
  for(i=1; i<n-1; ++i) {
    a = arr[i];
    cur = i%2;
    pre = 1-cur;
    for(j=0; j<=20; ++j) dp[cur][j] = 0;
    for(j=0; j<=20; ++j) {
      if(j+a <= 20) dp[cur][j+a] += dp[pre][j];
      if(j-a >= 0) dp[cur][j-a] += dp[pre][j];
    }
  }
  printf("%lld",dp[cur][arr[n-1]]);
}
