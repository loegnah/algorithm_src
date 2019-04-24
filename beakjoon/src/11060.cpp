#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int NOT = 987654321;
int n;
int board[1001];
int cache[1001];

int dp(int cur)
{
  if(cur >= n) return NOT;
  if(cur == n-1) return 0;
  if(board[cur]==0) return NOT;
  int& ret = cache[cur];
  if(ret != -1) return ret;
  ret = NOT;
  for(int i=board[cur]; i>0; --i)
    ret = min(ret, 1+dp(cur+i));
  return ret;
}

int main()
{
  scanf("%d",&n);
  for(int i=0; i<n; ++i)
    scanf("%d",board+i);
  memset(cache,-1,sizeof cache);
  int ans;
  if(n==0) ans = 0;
  else {
    ans = dp(0);
    if(ans == NOT) ans = -1;
  }
  printf("%d",ans);
}
