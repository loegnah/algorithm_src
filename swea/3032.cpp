// 확장 유클리드 알고리즘 이용 //

#include <cstdio>
using namespace std;

long long ret1,ret2,tmp;

void solve(long long a,long long b)
{
  if(a%b==1LL) {
    ret1 = 1;
    ret2 = -(a/b);
    return;
  }
  solve(b,a%b);
  tmp = ret2;
  ret2 = (-a/b)*ret2+ret1;
  ret1 = tmp;
}

int main()
{
  int t;
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    long long a,b;
    scanf("%lld %lld",&a,&b);
    solve(a,b);
    printf("#%d %lld %lld\n",tc,ret1,ret2);
  }
}
