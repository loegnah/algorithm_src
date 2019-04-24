#include <cstdio>
using namespace std;

int N,M,s,e;
int num[2002];
int sameLen[2002][2];

void preProcess()
{
  int a, b, c, len;
  a = 0;
  for(int i=1; i<=N; ++i) {
    len = 0;
    for(int j=1; (i-j>=1 && i+j<=N) ; ++j) {
      b = i-j;
      c = i+j;
      if(num[b] != num[c]) break;
      ++len;
    }
    sameLen[i][a] = len;
  }
  a = 1;
  for(int i=1; i<=N-1; ++i) {
    len = 0;
    for(int j=1; (i-j+1>=1 && i+j<=N) ; ++j) {
      b = i-j+1;
      c = i+j;
      if(num[b] != num[c]) break;
      ++len;
    }
    sameLen[i][a] = len;
  }
}

int solve()
{
  int mid = (s+e)/2;
  int dif = ((e-s)%2==0 ? 0 : 1);
  int len = e-mid;
  if(len > sameLen[mid][dif]) return 0;
  return 1;
}

int main()
{
  scanf("%d",&N);
  for(int i=1; i<=N; ++i)
    scanf("%d",num+i);
  preProcess();
  scanf("%d",&M);
  while(M--) {
    scanf("%d %d",&s,&e);
    printf("%d\n",solve());
  }
}
