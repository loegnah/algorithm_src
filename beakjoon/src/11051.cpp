#include <cstdio>
using namespace std;

const int MOD = 10007;
int N,K;
int c[2][1002];

int main()
{
  scanf("%d %d",&N,&K);
  c[1][0] = c[1][1] = 1;
  c[1][2] = 0;
  for(int n=2; n<=N; ++n) {
    int i = (n%2);
    int j = (n+1)%2;
    c[i][0] = 1;
    for(int k=1; k<=n; ++k)
      c[i][k] = (c[j][k] + c[j][k-1])%MOD;
  }
  printf("%d",c[N%2][K]);
}
