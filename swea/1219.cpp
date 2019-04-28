#include <cstdio>
using namespace std;

int t,m,adj[200],isFirst[100],isVisit[101];

void dfs(int cur)
{
    isVisit[cur] = 1;
    if(!isVisit[adj[cur+cur]]) dfs(adj[cur+cur]);
    if(!isVisit[adj[cur+cur+1]]) dfs(adj[cur+cur+1]);
}

int main()
{
    int a,b;
    isVisit[100] = 1;
    for(int tc=1; tc<=10; ++tc) {
        for(int i=0; i<100; ++i) {
            isVisit[i] = isFirst[i] = 0;
            adj[i+i] = adj[i+i+1] = 100;
        }

        scanf("%d %d",&t,&m);
        for(int i=0; i<m; ++i) {
            scanf("%d %d",&a,&b);
            adj[a+a+isFirst[a]] = b;
            isFirst[a]++;
        }

        dfs(0);
        printf("#%d %d\n",t,isVisit[99]);
    }

}
