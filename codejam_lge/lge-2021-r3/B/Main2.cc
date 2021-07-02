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

const int maxn = 32;
const ll limit = 1ll << 56;

class P2 { 
  int n, ans;
  ll val[maxn];
public:
  
  void doit(int d, ll lH, ll lL) {
    if(d == n) {
      ans++;
      return;
    }
    ll nH = 0, nL = 0;
    for(int i = d; i < n; i++) {
      nH = nH * 16ll;
      nL = nL * 16ll + val[i];
      while(nL >= limit) {
        ll v = nL / limit;
        nL -= limit * v;
        nH+= v;
      }
      if(nH > lH || (nH == lH && nL >= lL))
        doit(i+1, nH, nL);
    }
  }
  
  int solve(string x) {
    n = x.size();
    FOR(i,0,n) {
      if(x[i] <= '9') val[i] = x[i] - '0';
      else val[i] = 10 + (x[i] - 'A');
    }
    ans = 0;
    doit(0, 0, 0);
    return ans;
  }
};

int main() {  
	int t;
	scanf("%d", &t);
	P2 *inst = new P2();
	while(t--) {
    char dat[32];
    scanf("%s", dat);
    printf("%d\n", inst->solve(dat));
	}
  return 0;
}
