#include <cstdio>
#include <cstring>
#include <algorithm>
#include <limits>
using namespace std;

const int INT_MIN = numeric_limits<int>::min();
const int MN = -100010000;

int n,m;
int arr[1001][1001];
int cache[1001][1001][3];

int dp(int y,int x, int dir)
{
  if(y==n-1 && x==m-1) return arr[y][x];
  if(y>=n || y<0 || x>=m || x<0) return MN;
  int& ret = cache[y][x][dir+1];
  if(ret != INT_MIN) return ret;
  ret = arr[y][x];
  if(dir==0) ret += max(dp(y+1,x,0),max(dp(y,x+1,1),dp(y,x-1,-1)));
  else ret += max(dp(y+1,x,0),dp(y,x+dir,dir));
  return ret;
}

int main()
{
  scanf("%d %d",&n,&m);
  for(int i=0; i<n; ++i)
    for(int j=0; j<m; ++j) {
      scanf("%d",&arr[i][j]);
      cache[i][j][0] = cache[i][j][1] = cache[i][j][2] = INT_MIN;
    }
  printf("%d",dp(0,0,1));
}
