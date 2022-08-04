#include<cassert>
#include<vector>
#include<cstdio>
#include<map>
#include<set>
#include<cstring>
#include<cstring>
#include<memory>
#include<algorithm>
#include<string>
#include<iostream>
#include<queue>
using namespace std;
#define FOR(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)
#define FORE(it,x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); ++it)
#define pb push_back
typedef long long ll;

const int maxn = 1048576;
const ll MOD = 1000000000+7;

int n, k;
int ind[maxn];
char buff[maxn];

class Sol {
  
  ll pow_mod(ll x, ll e) {
    if(e == 0) return 1;
    if(e == 1) return x;
    ll x2 = pow_mod(x, e/2);
    x2 = (x2 * x2) % MOD;
    if(e % 2 == 1) {
      x2 = (x2 * x) % MOD;
    }
    return x2;
  }

  ll binom_mod(ll nn, ll kk) {
    if(kk < 0 || kk > nn || nn < 0) return 0;
    if(nn == kk || kk == 0) return 1;

    ll ans = 1;
    for(ll num = nn; num >= nn-kk+1; num--) {
      ans = (ans * num)%MOD;
    }
    for(ll num = 1; num <= kk; num++) {
      ans = (ans * pow_mod(num, MOD-2)) % MOD;
    }
    return ans;
  }
  
public:
  ll solve() {
    int cnt = 0;
    FOR(i,0,n) {
      if(buff[i] == '1') {
        cnt++;
        ind[cnt] = i;
      }
    }
    if(cnt % k != 0) return 0;
    if(cnt == 0) {
      return binom_mod(n-1, k-1);
    }
    
    int unit = cnt / k;
    ll ans = 1;
    for(int i = 1; i < k; i++) {
      int i1 = ind[unit*i];
      int i2 = ind[unit*i + 1];
      ll v = (i2 - i1);
      ans = ans * v;
      ans %= MOD;
    }
    
    return ans;
  }
};

int main() {

	Sol* ins = new Sol();  
  int t;
  scanf("%d", &t);
  
  while(t--) {
    scanf("%d%d",&n, &k);
    scanf("%s", buff);
    
    printf("%lld\n", ins->solve());
  }
	return 0;
}

