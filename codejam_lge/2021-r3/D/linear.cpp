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

const int maxn = 1048576*5;

ll H[maxn], W[maxn], v[maxn];
int bg[maxn];

class P4 { 
  
public:
  ll solve(int n, ll x) {
    ll maxi = -1ll;
    int nb = 0, ib = 0;
    bg[nb++] = 0;

    FOR(i,1,n) {
      while(ib < nb && H[i] - H[bg[ib]] > x) ib++;
      if(ib < nb) {
        maxi = max(maxi, v[i] + v[bg[ib]]);
      }
      while(ib < nb && v[i] >= v[bg[nb-1]]) nb--;
      bg[nb++] = i;
    }
    
    return maxi;
  }
};

int main() {
	int t;
	scanf("%d", &t);
	P4 *inst = new P4();
	while(t--) {
    int n, x;
    scanf("%d%d", &n, &x); 
    
    int hs, ha, hb, hc;
    scanf("%d%d%d%d", &hs, &ha, &hb, &hc);

    int ws, wa, wb, wc;
    scanf("%d%d%d%d", &ws, &wa, &wb, &wc);

    H[0] = hs % hc + 1;
    W[0] = ws % wc + 1;
    v[0] = H[0] * W[0];
    for(int i = 1; i <= n-1; i++) {
      H[i] = H[i-1] + 1 + (H[i-1] * ha + hb) % hc;
      W[i] = (W[i-1] * wa + wb) % wc + 1;
      v[i] =  W[i] * H[i];
    }
          
    ll ans = inst->solve(n, x);
    
    printf("%lld\n", ans);
	}

  return 0;
}

