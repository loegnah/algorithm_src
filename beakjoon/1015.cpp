#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main()
{
    int N, ipt;
    vector<pair<int,int>> b;

    scanf("%d",&N);
    for(int i=0; i<N; ++i) {
        scanf("%d",&ipt);
        b.push_back(pair<int,int>(ipt,i));
    }

    sort(b.begin(),b.end());
    
    vector<int> ans(N+1);
    for(int i=0; i<N; ++i) ans[b[i].second] = i;

    for(int i=0; i<N; ++i) printf("%d ",ans[i]);
}