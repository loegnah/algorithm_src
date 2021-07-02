#include<set>
#include<map>
#include<cassert>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cstring>
#include<memory>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define FORE(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); ++it)
typedef long long ll;

const int maxn = 524288;
const ll M = 24*60*60;

int dat[maxn], tim[maxn];

class P3 { 
  
public:
  
  ll gcd(ll x, ll y) {
    while(y > 0) {
      ll z = x % y;
      x = y;
      y = z;
    }
    return x;
  }
  
  ll exp(ll x, ll e, ll m) {
    if(e == 0) return 1ll;
    if(e == 1) return x;
    ll ans = exp(x, e/2, m);
    ans = (ans * ans) % m;
    if(e % 2 == 1) ans = (ans * x) % m;
    return ans;
  }
  
  ll inv(ll aa, ll mm) {
    ll phi = 1, m_org = mm;
    for(ll dv = 2; dv <= 5; dv++) {
      int cp = 0;
      while(m_org > 1 && m_org % dv == 0) {
        m_org /= dv;
        cp++;
      }
      if(cp > 0) {
        FOR(k,0,cp) phi *= dv;
        phi *= dv - 1;
      }
    }
    return exp(aa, phi-1, mm);
  }
  
  ll solve(int n) {
    int val[(int) M+1], nv[(int) M+1], cnt[(int) M+1];
    memset(val, -1, sizeof(val));
    memset(nv, 0, sizeof(nv));
    FOR(i,1,n) {
      ll a = ((dat[i]%M - dat[0]%M)%M + M ) % M;
      ll b = ((tim[0] - tim[i]) + M ) % M;
      ll g = gcd(a, M);
      if(b % g != 0) return 0;
      
      ll aa = a / g, bb = b / g, mm = M / g;
      ll x = (bb * inv(aa, mm)) % mm;
      if(val[mm] != -1 && val[mm] != x) return 0;
      val[mm] = x;
      nv[mm]++;
    }
    memset(cnt, 0, sizeof(cnt));
    int ans = 0;
    FOR(mm,1,M+1) {
      if(val[mm] != -1) {
        for(int x = val[mm]; x < M; x += mm) {
          cnt[x] += nv[mm];
          if(cnt[x] == n-1) ans++;
        }
      }
    }
    return ans;
  }
};

int main() {  
	int t;
	scanf("%d", &t);
	P3 *inst = new P3();
	while(t--) {
    int n;
    scanf("%d", &n);
    char buff[16];
    FOR(i,0,n) {
      scanf("%s", buff);
      int hh, mm, ss;
      sscanf(buff, "%d:%d:%d", &hh, &mm, &ss);
      tim[i] = ss + mm*60 + hh*3600;
    }
    FOR(i,0,n) scanf("%d", &dat[i]);
    printf("%lld\n", inst->solve(n));
	}
  return 0;
}

