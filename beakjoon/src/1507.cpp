#include <cstdio>
using namespace std;

int main()
{
  int n,adj[22][22],ans=0;
  scanf("%d",&n);
  for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) scanf("%d",&adj[i][j]);

  for(int i=0; i<n; ++i)
    for(int j=i+1; j<n; ++j) {
      bool ck = true;
      for(int k=0; k<n; ++k) {
        if(k==i || k==j) continue;
        if(adj[i][j] == adj[i][k] + adj[k][j]) {
          ck = false;
          break;
        }
        else if(adj[i][j] > adj[i][k] + adj[k][j]) {
          printf("-1");
          return 0;
        }
      }
      if(ck) ans += adj[i][j];
    }
  printf("%d",ans);
}
