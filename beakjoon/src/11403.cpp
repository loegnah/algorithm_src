#include <cstdio>
#include <vector>
using namespace std;

int n;
int adj[100][100];
vector<int> isVisited;

void dfs(int here) {
  isVisited[here]++;
  for(int there=0; there<n; ++there) {
    if(adj[here][there] && !isVisited[there])
      dfs(there);
  }
}

int main()
{
  scanf("%d",&n);
  for(int i=0; i<n; ++i)
    for(int j=0; j<n; ++j)
      scanf("%d",&adj[i][j]);
  for(int i=0; i<n; ++i) {
    isVisited = vector<int>(n,0);
    isVisited[i] = -1;
    dfs(i);
    for(int j=0; j<n; ++j)
      printf("%d ",isVisited[j]);
    printf("\n");
  }

}
