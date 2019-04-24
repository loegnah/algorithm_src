#include <cstdio>
#include <cstring>
using namespace std;

int n;
int arr[502][502] = {0};
int cache[502][502];
int cx[4] = {-1,0,1,0};
int cy[4] = {0,1,0,-1};

int dp(int y, int x)
{
  int& ret = cache[y][x];
  if(ret != -1) return ret;
  ret = 1;
  int tmp = 0, cur = arr[y][x];
  for(int i=0; i<4; ++i) {
    if(cur < arr[y+cy[i]][x+cx[i]]) {
      tmp = 1+dp(y+cy[i],x+cx[i]);
      ret = ret > tmp ? ret : tmp;
    }
  }
  return ret;
}

int main()
{
  memset(cache,-1,sizeof cache);
  scanf("%d",&n);
  for(int i=1; i<=n; ++i)
    for(int j=1; j<=n; ++j)
      scanf("%d",&arr[i][j]);

  int ret, ans = 0;
  for(int y=1; y<=n; ++y)
    for(int x=1; x<=n; ++x) {
      ret = dp(y,x);
      ans = ans > ret ? ans : ret;
    }
  printf("%d",ans);
}
