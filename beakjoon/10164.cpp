#include <cstdio>
using namespace std;

int N,M,K;
int arr[15][15];

void pre()
{
  for(int i=0; i<15; ++i) {
    arr[0][i] = 1;
    arr[i][0] = 1;
  }
  for(int i=1; i<15; ++i)
    for(int j=1; j<15; ++j)
      arr[i][j] = arr[i-1][j] + arr[i][j-1];
}

int main()
{
  scanf("%d %d %d",&N,&M,&K);
  pre();
  N--; M--;
  if(K!=0) K--;
  int n1 = K/(M+1), m1 = K%(M+1);
  int n2 = N-n1, m2 = M-m1;
  printf("%d %d %d %d\n",n1,m1,n2,m2);
  printf("%d %d\n",arr[n1][m1], arr[n2][m2]);
  printf("%d",arr[n1][m1]*arr[n2][m2]);
}
