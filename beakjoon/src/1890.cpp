#include <cstdio>
#include <cstring>
using namespace std;

int N;
int arr[101][101];
long long comp = -1;
long long cache[103][103];

long long dp(int y, int x)
{
  if(y>N || x>N) return 0;
  if(y==N && x==N) return 1;
  long long& ret = cache[y][x];
  if(ret != comp) return ret;
  if(arr[y][x] == 0) return ret = 0;
  return ret = dp(y+arr[y][x],x) + dp(y,x+arr[y][x]);
}

int main()
{
  memset(cache,-1,sizeof cache);
  scanf("%d",&N);
  for(int i=1; i<=N; ++i)
    for(int j=1; j<=N; ++j)
      scanf("%d",&arr[i][j]);
  printf("%lld",dp(1,1));
}
