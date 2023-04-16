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
#define pq priority_queue
typedef long long ll;

const int maxn = 1048576*5;

ll H[maxn], W[maxn], v[maxn];

class Data {
  public: int idx;
};

struct Comp { 
  bool operator()(const Data& a, const Data& b) {
    return v[a.idx] < v[b.idx];
  }
};

class P4 { 
  
public:
  ll solve(int n, ll z) {
    ll maxi = -1;

    pq<Data, vector<Data>, Comp> hp; // max heap
    FOR(i,0,n) {
      while(!hp.empty() && H[i] - H[hp.top().idx] > z) hp.pop();
    
      if(!hp.empty()) {
        int j = hp.top().idx;
        maxi = max(maxi, v[i] + v[j]);
      }
    
      Data d; d.idx = i;
      hp.push(d);
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
    for(int i = 1; i <= n-1; i++) {
      H[i] = H[i-1] + 1 + (H[i-1] * ha + hb) % hc;
    }
    
    W[0] = ws % wc + 1;
    for(int i = 1; i <= n-1; i++) {
      W[i] = (W[i-1] * wa + wb) % wc + 1;
    }
    
    FOR(i,0,n) {
      // h[i] = H[i];
      // w[i] = W[i];
      // printf("%10lld x %10lld = %20lld\n", h[i], w[i], h[i] * w[i]);
      // assert(1 <= h[i] && h[i] <= 1000*1000*1000);
      // assert(1 <= w[i] && w[i] <= 1000*1000*1000);
      // if(i > 0) assert(h[i-1] < h[i]);
      // TODO :product (volume) <= 4 *  10^18
      v[i] = H[i] * W[i];
    }
      
    ll ans = inst->solve(n, x);
    
    printf("%lld\n", ans);
	}
  
  return 0;
}

