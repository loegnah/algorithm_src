#include <cstdio>
using namespace std;

const int MX = 654321;
int n,m,adj[102][102];

void floyd()
{
  for(int k=1; k<=n; ++k)
    for(int u=1; u<=n; ++u)
      for(int v=1; v<=n; ++v) {
        if(u==v || adj[u][k] == MX || adj[k][v] == MX) continue;
        if(adj[u][v] > adj[u][k] + adj[k][v])
          adj[u][v] = adj[u][k] + adj[k][v];
      }
}

int main()
{
  int a,b,c;
  scanf("%d",&n);
  scanf("%d",&m);
  for(int y=1; y<=n; ++y)
    for(int x=1; x<=n; ++x)
      adj[y][x] = MX;
  for(int i=0; i<m; ++i) {
    scanf("%d %d %d",&a,&b,&c);
    if(adj[a][b] > c) adj[a][b] = c;
  }

  floyd();

  for(int y=1; y<=n; ++y) {
    for(int x=1; x<=n; ++x) {
      if(adj[y][x]==MX) printf("0 ");
      else printf("%d ",adj[y][x]);
    }
    printf("\n");
  }
}
