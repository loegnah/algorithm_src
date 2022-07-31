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
#define pb push_back
typedef long long ll;

const int maxn = 16384;
const int maxk = 64;

class P1 { 
  int n, k;
  map<vector<int>, int> cnt[maxk];

public:
  ll solve(vector<string>& dat) {
    n = dat.size();
    k = dat[0].size();
    
    FOR(j,0,k+1) cnt[j].clear();
    
    vector<int> val;
    val.resize(26);
    FOR(i,0,n) {
      int cu = 0;
      FOR(j,0,26) val[j] = 0;
      FOR(j,0,k) {
        if('A' <= dat[i][j] && dat[i][j] <= 'Z') cu++;
        int v = dat[i][j] - 'A';
        if(dat[i][j] >= 'a') v = dat[i][j] - 'a';
        val[v]++;
      }
      // printf("i = %d [%s] cu = %d val: ", i, dat[i].c_str(), cu);
      // FORE(it, val) printf("%d ", *it);
      // printf("\n");
      cnt[cu][val]++;
    }
    ll ans = 0;
    FOR(i,0,k+1) {
      FORE(it, cnt[i]) {
        ll v = it->second;
        ans += v*(v-1) / 2;
      }
    }

    return ans;
  }
};

int main() {  
	int t;
	scanf("%d", &t);
	P1 *inst = new P1();
	while(t--) {
    int n,k;
    scanf("%d%d", &n,&k);
    vector<string> dat;
    FOR(i,0,n) {
      char buff[maxn];
      scanf("%s", buff);
      dat.pb(string(buff));
    }
    printf("%lld\n", inst->solve(dat));
	}
  return 0;
}

