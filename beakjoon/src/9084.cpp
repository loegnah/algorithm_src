#include <cstdio>
#include <cstring>
using namespace std;

int n, goal;
int coin[22];
int cache[10002][22];

int dp(int tot, int c)
{
  if(tot > goal) return 0;
  if(tot == goal) return 1;
  int& ret = cache[tot][c];
  if(ret != -1) return ret;
  ret = 0;
  for(int i=c; i<n; ++i)
    ret += dp(tot+coin[i],i);
  return ret;
}

int main()
{
  int t;
  scanf("%d",&t);
  while(t--) {
    memset(cache,-1,sizeof cache);
    scanf("%d",&n);
    for(int i=0; i<n; ++i)
      scanf("%d",coin+i);
    scanf("%d",&goal);
    printf("%d\n",dp(0,0));
  }
}
