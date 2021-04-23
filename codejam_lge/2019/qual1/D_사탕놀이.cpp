#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MOD = 1000000007;

int N, X[205], cache[205][205];

void input()
{
    scanf("%d",&N);
    for(int i=0; i<N; ++i) scanf("%d",X+i);
}

int dp(int cur, int preNum)
{
    if(cur == N-1) return (X[cur]-preNum+1)*N;
    
    int& ret = cache[cur][preNum];
    if(ret != -1) return ret;

    ret = 0;
    for(int curNum=preNum; curNum <= X[cur]; ++curNum)
        ret = (ret + dp(cur+1,curNum)) % MOD;
    
    return ret;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--) {
        input();
        sort(X,X+N);
        memset(cache,-1,sizeof(cache));
        printf("%d\n",dp(0,1));
    }
}