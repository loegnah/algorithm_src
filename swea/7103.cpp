#include <cstdio>
#include <cstring>
using namespace std;

const int MX = 32767;
const int SQRT_MX = 181;

int cache[MX+3][SQRT_MX+3][4];
int N;

int dp(int rmn, int pre, int idx)
{
    if(rmn == 0) return 1;
    if(idx == 4 || (pre==0)) return 0;
    if(rmn > pre*pre*(4-idx)) return 0;

    int& ret = cache[rmn][pre][idx];
    if(ret != -1) return ret;

    ret = 0;
    int nxt = pre;
    while(rmn<nxt*nxt) --nxt;
    while(nxt>=0) {
        ret += dp(rmn-nxt*nxt, nxt, idx+1);
        --nxt;
    }
    
    return ret;
}

int main()
{
    int T;
    scanf("%d",&T);
    
    memset(cache,-1,sizeof(cache));
    for(int tc=1; tc<=T; ++tc) {

        scanf("%d",&N);
        printf("#%d %d\n",tc,dp(N,SQRT_MX,0));
    }
}