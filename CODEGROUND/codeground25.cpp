/*
  3N+1
  먼가 역발상의 문제.
  3N+1을 반대로할 때 조건이 까다롭다.
  소스코드 베꼇다 거의..
  DP그런거 안쓴다. 그냥 범위 잘성정하고 일단 제출해보는 느낌
*/

#include <cstdio>
using namespace std;

unsigned long long mx,mn;

void findNum(unsigned long long n,int k)
{
  if(k==0) {
    if(n>mx) mx = n;
    if(n<mn) mn = n;
    return;
  }
  if(n>1 && (n-1)%3==0 && ((n-1)/3)%2!=0 && (n-1)/3!=1)
      findNum((n-1)/3,k-1);
  findNum(n*2,k-1);
}

int main()
{
  int T,K;
  scanf("%d",&T);
  for(int tc=1; tc<=T; ++tc) {
    scanf("%d",&K);
    mn = 0xffffffffffffffffL;
    mx = 0;
    findNum(1,K);
    printf("Case #%d\n%llu %llu\n",tc,mn,mx);
  }
}
