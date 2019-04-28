/*
팩토리얼 먼저 계산해놓음
특정 좌표까지 가는 경로 값이 y+x(C)y 인데
이 떄 (y+x)!/(y!x!) 이고 각각의 나누기 연산 /y! /x!을 페르마 소정리로 inverse 가능하다.
즉 fac_inv(y), fac_inv(x)를 곱하는 것으로 바꿀 수 있음. 페르마 소정리는 에버노트에 사이트 경로있다.

*/
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

const long long MOD = 1000000007;
vector<pair<int,int> > obs;
int n,m,k;
long long fac[200005], fac_inv[100005], cache[2005];

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
  fac[0] = fac_inv[0] = 1LL;
  for(long long i=1; i<=100000; ++i) {
    fac[i] = (fac[i-1]*i)%MOD;
    fac_inv[i] = mul(fac[i],MOD-2);
  }
  for(long long i=100001; i<=200000; ++i) {
    fac[i] = (fac[i-1]*i)%MOD;
  }
}

long long calc_path(int y, int x)
{
  return (((fac[y+x-2]*fac_inv[y-1])%MOD)*fac_inv[x-1])%MOD;
}

long long not_obs_path(int cur)
{
  long long &ret = cache[cur];
  if(ret!=-1LL) return ret;

  int cy = obs[cur].first, cx = obs[cur].second;
  long long tot = 0;

  for(int i=0; i<cur; ++i) {
    int ny = obs[i].first, nx = obs[i].second;
    if(nx>cx) continue;
    tot = (tot+not_obs_path(i)*calc_path(cy-ny+1,cx-nx+1))%MOD;
  }
  ret = (calc_path(cy,cx)-tot+MOD)%MOD;
  return ret;
}

int main()
{
  int t,a,b;
  setbuf(stdout,NULL);

  calc_fac();
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    obs.clear();
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0; i<k; ++i) {
      scanf("%d %d",&a,&b);
      obs.push_back(make_pair(a,b));
    }
    sort(obs.begin(),obs.end());
    obs.push_back(make_pair(n,m));
    for(int i=0; i<k+1; ++i) cache[i] = -1LL;

    long long ans = not_obs_path(k);
    printf("Case #%d\n%lld\n",tc,ans);
  }
}
