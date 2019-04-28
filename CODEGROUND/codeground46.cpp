#include <cstdio>
using namespace std;

const int MX_INT = 987654321;
int t,n,m,k,a,b,c,p,s,e;
int dist[102][102];

void calc_dist()
{
  for(int t=1; t<=n; ++t)
    for(int u=1; u<=n; ++u)
      for(int v=u+1; v<=n; ++v) {
        if(dist[u][t]+dist[t][v] < dist[u][v])
          dist[u][v] = dist[v][u] = dist[u][t] + dist[t][v];
      }
}

void check()
{
  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=n; ++j) {
      if(dist[i][j]>=MX_INT) printf(" %3c",'X');
      else printf(" %3d",dist[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

int main(int argc,char** argv)
{
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    scanf("%d %d %d",&n,&m,&k);
    for(int u=1; u<=n; ++u) {
      dist[u][u] = 0;
      for(int v=u+1; v<=n; ++v)
        dist[u][v] = dist[v][u] = MX_INT;
    }
    for(int i=0; i<m; ++i) {
      scanf("%d %d %d",&a,&b,&c);
      dist[a][b] = dist[b][a] = c;
    }
    check();
    calc_dist();
    check();
    scanf("%d",&p);
    int ans = 0, d;
    while(p--) {
      scanf("%d %d",&s,&e);
      if(k<dist[s][e]) ans++;
    }
    printf("Case #%d\n%d\n",tc,ans);
  }
}
