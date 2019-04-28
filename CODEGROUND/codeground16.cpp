#include <cstdio>
#include <cmath>
using namespace std;

int t,m;
long long a,b,dif;

long long gcdll(long long x, long long y)
{
  if(y>x) return gcdll(y,x);
  while(y) {
    long long tmp = y;
    y = x%y;
    x = tmp;
  }
  return x;
}

int dvsNum(long long n)
{
  if(n<=2) return (int)n;
  int ret = 2;
  long long i;
  for(i=2; i*i<n; ++i) {
    if(n%i==0) ret += 2;
  }
  if(i*i == n) ret +=1;
  return ret;
}

void exceptCase(int tc)
{
  int ans;
  if(a==b) ans = 1;
  else ans = dvsNum(b-a);
  printf("Case #%d\n",tc);
  printf("%d\n",ans);
}

int main(int argc, char** argv)
{
  setbuf(stdout,NULL);
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    int ans;
    scanf("%d",&m);
    scanf("%lld %lld",&a,&b);
    if(m==2) {
      exceptCase(tc);
      continue;
    }
    long long gcd = b-a;
    if(gcd==0) gcd = a;
    bool ck = (b==a);
    bool ansIsZero = false;
    a = b;

    for(int mm=2; mm<m; ++mm) {
      scanf("%lld",&b);
      if(ansIsZero || (ck != (b==a))) {
        ansIsZero = true;
        continue;
      }
      dif = b-a;
      if(gcd>1) gcd = gcdll(gcd,dif);
      a = b;
    }
    if(ansIsZero) ans = 0;
    else if(ck) ans = 1;
    else ans = dvsNum(gcd);
    printf("Case #%d\n",tc);
    printf("%d\n",ans);
  }
}
