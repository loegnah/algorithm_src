#include <cstdio>
using namespace std;

#define RANGE 1000000

const long long MOD = 1000000007;
long long fac[2000004];

long long mul(long long a, long long b)
{
  if(b==0) return 1;
  long long ret = mul(a,b>>1);
  ret = (ret*ret)%MOD;
  if(b&1) ret = (ret*a)%MOD;
  return ret;
}

void calc_fac()
{
  fac[0] = fac[RANGE+1] = 1LL;
  for(long long i=1; i<=RANGE; ++i) {
    fac[i] = (fac[i-1]*i)%MOD;
    fac[i+RANGE+1] = mul(fac[i],MOD-2);
  }
}

long long get_comb(int a, int b)
{
  return (((fac[a]*fac[b+1+RANGE])%MOD)*fac[a-b+1+RANGE])%MOD;
}

long long fac_sum(int n, int m)
{
  long long ret = 0;
  for(int i=0; i<=m; ++i) {
    ret += get_comb(n+i+1,n);
  }
  return ret%MOD;
}

int main()
{
  int t,n,m;
  setbuf(stdout,NULL);

  calc_fac();
  scanf("%d",&t);

  for(int tc=1; tc<=t; ++tc) {
    scanf("%d %d",&n,&m);
    long long ans = fac_sum(n,m);
    printf("Case #%d\n%lld\n",tc,ans);
  }
}
