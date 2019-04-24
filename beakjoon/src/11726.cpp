#include <cstdio>
#include <cstring>
using namespace std;

const int MOD = 10007;
int cache[1002];

int dp(int k)
{
    if((k==1) || (k==0)) return 1;
    if(k<0) return 0;
    
    int& ret = cache[k];
    if(ret != -1) return ret;
    
    return ret = (dp(k-2)%MOD + dp(k-1)%MOD) % MOD;

}

int main()
{
    int n;
    memset(cache,-1,sizeof(cache));
    scanf("%d",&n);
    printf("%d\n",dp(n));   
}
