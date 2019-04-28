#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int t,n,m,a,b;
vector<int> adj[202];

bool solve()
{
  queue<int> q;
  vector<int> check(n+1,-1);
  int visitNum = 0;
  q.push(1);
  check[1] = 1;
  while(!q.empty()) {
    int hear = q.front();
    q.pop();
    int me = check[hear];
    for(int i=0; i<adj[hear].size(); ++i) {
      int next = adj[hear][i];
      int you = 1-me;
      if(check[next]==me) return false;
      else if(check[next] == you) continue;
      else {
        check[next] = you;
        q.push(next);
      }
    }
  }
  return true;
}

int main()
{
  setbuf(stdout,NULL);
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=1; i<=n; ++i) adj[i].clear();
    for(int i=0; i<m; ++i) {
      scanf("%d %d",&a,&b);
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    int ans;
    if(solve()) ans = 1;
    else ans = 0;
    printf("Case #%d\n%d\n",tc,ans);
  }
}
