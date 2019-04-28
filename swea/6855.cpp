#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;

int main()
{
    int T, N, K, a, b, ans;
    scanf("%d",&T);
    for(int tc=1; tc<=T; ++tc) {
        scanf("%d %d",&N, &K);
        
        v.clear();
        scanf("%d",&a);
        for(int i=1; i<N; ++i) {
            scanf("%d",&b);
            v.push_back(b-a);
            a = b;
        }

        sort(v.begin(), v.end());

        ans = 0;
        for(int i=0; i<N-K; ++i) ans += v[i];
        printf("#%d %d\n", tc, ans);
    }
}