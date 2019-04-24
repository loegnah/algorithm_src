#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int n,m;
int st,en;
vector<int> adj[102];
int c[102];

void bfs()
{
  queue<int> q;
  q.push(st);
  c[st] = 0;
  while(!q.empty()) {
    int cur = q.front();
    q.pop();
    if(cur == en) return;
    for(int i=0; i<adj[cur].size(); ++i) {
      int nxt = adj[cur][i];
      if(c[nxt] == -1) {
        c[nxt] = c[cur] +1;
        q.push(nxt);
      }
    }
  }
}

int main()
{
  int a,b;
  scanf("%d",&n);
  scanf("%d %d",&st,&en);
  scanf("%d",&m);
  for(int i=0; i<m; ++i) {
    scanf("%d %d",&a,&b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  memset(c,-1,sizeof c);
  bfs();
  printf("%d",c[en]);
}
