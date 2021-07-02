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

class P4 { 
  int heap[maxn], nh;
  
  void del_root() {
    heap[0] = heap[--nh];
    int w = 0;
    while(w*2+1 < nh) {
      int lf = w*2+1, rt = w*2+2, next = -1;
      if(lf < nh) next = lf;
      if(rt < nh && compare(rt, lf)) next = rt;
      if(!compare(next, w)) break;
      int tmp = heap[w]; heap[w] = heap[next]; heap[next] = tmp;
      w = next;
    }
  }
  
  bool compare(int w1, int w2) {
    return v[heap[w1]] > v[heap[w2]];
  }
  
  void up(int w) {
    while(w > 0) {
      int p = (w-1)/2;
      if(compare(w, p)) {
        int tmp = heap[w]; heap[w] = heap[p]; heap[p] = tmp;
        w = p;        
      } else break;
    }
  }
  
public:
  ll solve(int n, ll z) {
    ll maxi = -1;

    nh = 0;
    FOR(i,0,n) {
      while(nh > 0 && H[i] - H[heap[0]] > z) del_root();

      if(nh > 0) {
        maxi = max(maxi, v[i] + v[heap[0]]);
      }
      heap[nh++] = i;
      up(nh-1);
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
    
    FOR(i,0,n) v[i] = H[i] * W[i];
          
    ll ans = inst->solve(n, x);
    
    printf("%lld\n", ans);
	}

  return 0;
}

