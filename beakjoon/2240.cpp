#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int t,w;
int tree[1002];
int cache[1002][32][2];

int dp(int cur_time, int rmn_mv, int cur_tree)
{
  if(cur_time == t) {
    if(cur_tree == tree[cur_time]) return 1;
    else return 0;
  }
  int& ret = cache[cur_time][rmn_mv][cur_tree-1];
  if(ret != -1) return ret;
  ret = dp(cur_time+1,rmn_mv,cur_tree);
  if(rmn_mv != 0) ret = max(ret,dp(cur_time+1,rmn_mv-1, 3-cur_tree));
  if(cur_tree == tree[cur_time]) ret += 1;
  return ret;
}

int main()
{
  memset(cache,-1,sizeof cache);
  scanf("%d %d",&t,&w);
  for(int i=1; i<=t; ++i)
    scanf("%d",tree+i);
  printf("%d",dp(0,w,1));
}
