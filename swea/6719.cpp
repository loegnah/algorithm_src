#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int T,N,K,nums[201];
    scanf("%d",&T);
    for(int tc=1; tc<=T; ++tc) {
        double ans = 0.0;
        
        scanf("%d %d",&N,&K);
        for(int i=0; i<N; ++i) scanf("%d",nums+i);

        sort(nums,nums+N);
        
        for(int i=N-K; i<N; ++i) ans = (ans+nums[i])/2.0;
        
        printf("#%d %.6lf\n",tc,ans);
    }
}