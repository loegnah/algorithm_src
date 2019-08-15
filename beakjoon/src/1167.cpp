#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

using PILL = pair<int, long long>;
using VP = vector<PILL>;

const int MX_NODE_CNT = 100005;

int V;
VP node[MX_NODE_CNT]; 
long long max2len[MX_NODE_CNT][2];
bool isVisited[MX_NODE_CNT];

long long findMaxLen()
{
    long long maxLen = 0;
    long long tmp = 0;

    for(int i=1; i<=V; ++i) {
        tmp = max2len[i][0] + max2len[i][1];
        maxLen = (tmp > maxLen) ? tmp: maxLen;
    }

    return maxLen;
}

long long find2MaxLen(int cur, int pre)
{
    if(isVisited[cur]) return 0;
    isVisited[cur] = true;

    int childCnt = node[cur].size();
    if(childCnt == 1 && node[cur][0].first == pre) return 0;

    vector<long long> childLen;
    for(int i=0; i < childCnt; ++i) {
        if(node[cur][i].first == pre) continue;  
        childLen.push_back(-node[cur][i].second - find2MaxLen(node[cur][i].first, cur));
    }
    
    sort(childLen.begin(), childLen.end());
    max2len[cur][0] = -childLen[0];
    if(childLen.size() > 1) max2len[cur][1] = -childLen[1];

    return max2len[cur][0];
}

long long solve()
{
    find2MaxLen(1,0);
    return findMaxLen();
}

int main()
{
    int a, b;
    long long w;

    scanf("%d", &V);

    for(int i=1; i<=V; ++i) {
        scanf("%d", &a);
        node[a].clear();
        max2len[a][0] = max2len[a][1] = 0;
        isVisited[a] = false;

        while(true) {
            scanf("%d", &b);
            if(b == -1) break;
            scanf("%lld", &w);
            
            node[a].push_back(PILL(b,w));
        }
    }

    printf("%lld\n",solve());
}