#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,k;
int value[102];
int cache[72][10002];

int dp(int cur, int tot)
{
  if(cur == n || tot > k) return 0;
  if(tot == k) return 1;
  if(cur < 70) {
    int& ret = cache[cur][tot];
    if(ret != -1) return ret;
    return ret = dp(cur+1,tot) + dp(cur,tot+value[cur]);
  }
  return dp(cur+1,tot) + dp(cur,tot+value[cur]);
}

int main()
{
  memset(cache,-1,sizeof cache);
  scanf("%d %d",&n,&k);
  for(int i=0; i<n; ++i) scanf("%d",value+i);
  printf("%d",dp(0,0));
}
