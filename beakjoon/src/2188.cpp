#include <cstdio>
#include <vector>
using namespace std;

int N,M,si,ipt;
vector<int> adj[202];
vector<bool> isVisited;
vector<int> aMatch, bMatch;

bool dfs(int a)
{
  int b;
  if(isVisited[a]) return false;
  isVisited[a] = true;
  for(int i=0; i<(int)adj[a].size(); ++i) {
    b = adj[a][i];
    if(bMatch[b] == -1 || dfs(bMatch[b])) {
      aMatch[a] = b;
      bMatch[b] = a;
      return true;
    }
  }
  return false;
}

int main()
{
  scanf("%d %d",&N,&M);
  for(int i=1; i<=N; ++i) {
    scanf("%d",&si);
    for(int j=0; j<si; ++j) {
      scanf("%d",&ipt);
      adj[i].push_back(ipt);
    }
  }
  int ans = 0;
  aMatch = vector<int>(N+1,-1);
  bMatch = vector<int>(M+1,-1);
  for(int st=1; st<=N; ++st) {
    isVisited = vector<bool>(N+1,false);
    if(dfs(st))
      ++ans;
  }
  printf("%d",ans);
}
