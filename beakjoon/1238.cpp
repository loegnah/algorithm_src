#include <cstdio>
using namespace std;

const int INF = 1000000007;
int N,M,X;
int adj[1003][1003];

void floyd()
{
  for(int k=1; k<=N; ++k)
    for(int u=1; u<=N; ++u)
      for(int v=1; v<=N; ++v) {
        if(adj[u][k]==INF || adj[k][v]==INF) continue;
        if(adj[u][v]>adj[u][k]+adj[k][v])
          adj[u][v] = adj[u][k]+adj[k][v];
      }
}

int find_longTime(int x)
{
  int mx = -1, dist;
  if(N==1) return 0;
  for(int i=1; i<=N; ++i) {
    if(i==x) continue;
    dist = adj[i][x]+adj[x][i];
    if(mx<dist) mx = dist;
  }
  return mx;
}

int main()
{
  int a,b,c;
  scanf("%d %d %d",&N,&M,&X);
  for(int i=1; i<=N; ++i) for(int j=1; j<=N; ++j) adj[i][j] = INF;
  for(int i=0; i<M; ++i) {
    scanf("%d %d %d",&a,&b,&c);
    adj[a][b] = c;
  }
  floyd();
  printf("%d",find_longTime(X));
}
