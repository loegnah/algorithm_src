#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;

stack<int> st;
bool adj[11][11];
bool isVisit[11];
int ans,n,m;

void solve(int here, int count) {
  if(ans < count) ans = count;
  for(int i=1; i<=n; ++i) {
    if(adj[here][i] && !isVisit[i]) {
      isVisit[i] = true;
      solve(i,count+1);
      isVisit[i] = false;
    }
  }
}

int main()
{
  int t,a,b;
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {

    memset(adj,0,sizeof adj);
    memset(isVisit,0,sizeof isVisit);
    ans = 0;

    scanf("%d %d",&n,&m);
    for(int i=0; i<m; ++i) {
      scanf("%d %d",&a,&b);
      adj[a][b] = true;
      adj[b][a] = true;
    }

    for(int i=1; i<=n; ++i) {
      isVisit[i] = true;
      solve(i,1);
      isVisit[i] = false;
    }
    printf("#%d %d\n",tc,ans);
  }
}
