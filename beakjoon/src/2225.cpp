#include <cstdio>
using namespace std;

const int MOD = 1000000000;
int N,K;
int arr[201][2] = {0};

int main()
{
  scanf("%d %d",&N,&K);
  for(int i=0; i<=N; ++i)
    arr[i][1] = 1;
  for(int ct=2; ct<=K; ++ct) {
    int cur = ct%2, pre = (ct+1)%2;
    for(int i=0; i<=N; ++i) {
      arr[i][cur] = 0;
      for(int j=0; j<=i; ++j)
        arr[i][cur] = (arr[i][cur]+arr[i-j][pre])%MOD;
    }
  }
  printf("%d",arr[N][K%2]);
}
