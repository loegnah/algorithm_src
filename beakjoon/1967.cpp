#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

using VP = vector<pair<int,int>>;

int N;
VP node[10005]; 
int max2len[10005][2];

int findMaxLen()
{
    int maxLen = 0;
    int tmp = 0;

    for(int i=1; i<= N; ++i) {
        tmp = max2len[i][0] + max2len[i][1];
        maxLen = (tmp > maxLen) ? tmp: maxLen;
    }

    return maxLen;
}

int find2MaxLen(int cur)
{
    int childCnt = node[cur].size();

    if(childCnt == 0) return 0;
    if(childCnt == 1) return max2len[cur][0] = node[cur][0].second + find2MaxLen(node[cur][0].first);

    vector<int> childLen;
    for(int i=0; i < childCnt; ++i) 
        childLen.push_back(-node[cur][i].second - find2MaxLen(node[cur][i].first));
    
    sort(childLen.begin(), childLen.end());
    max2len[cur][0] = -childLen[0];
    max2len[cur][1] = -childLen[1];

    return max2len[cur][0];
}

int solve()
{
    find2MaxLen(1);
    return findMaxLen();
}

int main()
{
    int a,b,w;
    scanf("%d", &N);

    for(int i=1; i<=N; ++i) {
        node[i].clear();
        max2len[i][0] = max2len[i][1] = 0;
    }
    
    for(int i=1; i<=N-1; ++i) {
        scanf("%d %d %d", &a, &b, &w);
        node[a].push_back(pair<int,int>(b,w));
    }

    printf("%d\n",solve());
}