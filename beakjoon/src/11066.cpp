#include <cstdio>
#include <limits>
#include <algorithm>
using namespace std;

const int MX = numeric_limits<int>::max();
int t,k;
int c[503], ps[503], cache[503][503];


int dp(int a, int b)
{
  if(a==b) return 0;
  if(a==b-1) return c[a]+c[b];

  int& ret = cache[a][b];
  if(ret < MX) return ret;
  for(int i=a; i<b; ++i)
    ret = min(ret, dp(a,i)+dp(i+1,b));
  return ret = ret + ps[b] - ps[a-1];
}

int main()
{
  scanf("%d",&t);
  while(t--) {
    scanf("%d",&k);
    ps[0] = 0;
    for(int i=1; i<=k; ++i) {
      scanf("%d",c+i);
      ps[i] = ps[i-1] + c[i];
      for(int j=1; j<=k; ++j) cache[i][j] = MX;
    }
    printf("%d\n",dp(1,k));
  }
}
