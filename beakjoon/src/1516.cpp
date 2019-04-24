#include <iostream>
#include <vector>
using namespace std;

const int MX = 987654321;

int N;
vector<int> w, totTime;
vector<vector<bool>> adj;

inline int _max(const int a, const int b) { return a>b?a:b; }

int dfs(int cur)
{
    int& ret = totTime[cur];
    if(ret != -1) return ret;
    

    ret = 0;
    for(int there=0; there<N; ++there) {
        if(adj[cur][there]) ret = _max(ret,dfs(there));
    }
    ret += w[cur];
    return ret;
}

int main()
{   
    scanf("%d",&N);
    w = vector<int>(N,0);
    totTime = vector<int>(N,-1);
    adj = vector<vector<bool>>(N,vector<bool>(N,false));

    for(int i=0, wgt, prn; i<N; ++i) {
        scanf("%d",&wgt);
        w[i] = wgt;

        while(true) {
            scanf("%d",&prn);
            if(prn == -1) break;
            adj[i][prn-1] = true;
        }
    }

    for(int i=0; i<N; ++i) printf("%d\n",dfs(i));


}