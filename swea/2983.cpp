#include <cstdio>
#include <vector>
using namespace std;

const int MX_LEN = 200005;
const int MOD = 100000;

int L;
char S[MX_LEN];
vector<int> hs[MOD];

inline int mod(long long n){
    if(n >= 0) return n % MOD;
    return ((-n/MOD+1)*MOD + n) % MOD;
}

int solve()
{
    int lo = 0, hi = L;
    while(lo+1<hi) {
        int mid = (lo+hi)/2, k=0, power = 1, st=0;
        bool found = false;
        for(int i=0; i<MOD; ++i) hs[i].clear();

        for(int j=mid-1; j>=0; --j) {
            k = mod(k+1LL*S[j]*power);
            if(j>0) power = mod(power*2);
        }

        while(st<=L-mid) {
            if(!hs[k].empty()) {
                for(int st2 : hs[k]) {
                    int idx = 0;
                    while(idx<mid && (S[st+idx] == S[st2+idx])) idx++;
                    if(idx==mid) {found=true; break;}
                }
            }
            if(found) break;

            hs[k].push_back(st);
            k = mod(2*(k-1LL*S[st]*power)+S[st+mid]);
            st++;
        }
        if(found) lo = mid;
        else hi = mid;
    }
    return lo;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int tc=1; tc<=T; ++tc) {
        scanf("%d",&L);
        scanf("%s",S);

        printf("#%d %d\n",tc,solve());
    }
}
