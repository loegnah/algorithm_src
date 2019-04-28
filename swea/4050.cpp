#include <cstdio>
#include <cstring>
using namespace std;

int T,N,money[100005];

void input_init()
{
    int tmp;

    memset(money,0,sizeof(money));

    scanf("%d",&N);
    for(int i=0; i<N; ++i) {
        scanf("%d",&tmp);
        money[tmp]++;
    }
}

long long solve()
{
    long long ret = 0;
    int idx = 100000;

    for(int i=0; i<=(N-1)/3; ++i) {
        int count = 3;
        while(count) {
            while(idx>= 0 && money[idx] == 0) --idx;
            if(idx<0) break;

            money[idx]--;
            if(count > 1) ret += idx;
            count--; 
        }
    }
    return ret;
}

int main()
{
    scanf("%d",&T);
    for(int tc=1; tc<=T; ++tc) {
        input_init();
        long long ans = solve();
        printf("#%d %lld\n",tc,ans);
    }
}   