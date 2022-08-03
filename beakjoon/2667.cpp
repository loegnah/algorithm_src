#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int adj[27][27] = {0};
int cy[4] = {0,1,0,-1};
int cx[4] = {-1,0,1,0};

int dfs(int y,int x) {
  adj[y][x]=0;
  int ret = 1;
  for(int i=0; i<4; ++i)
    if(adj[y+cy[i]][x+cx[i]]) {
      ret += dfs(y+cy[i],x+cx[i]);
    }
  return ret;
}

int main()
{
  int ret, ct = 0;
  char ch[26];
  vector<int> ans;
  scanf("%d",&n);
  for(int i=1; i<n+1; ++i) {
    scanf("%s",ch);
    for(int j=0; j<n; ++j)
      adj[i][j+1]=ch[j]-'0';
  }
  for(int i=1; i<n+1; ++i)
    for(int j=1; j<n+1; ++j) {
      if(adj[i][j]) {
        ++ct;
        ret = dfs(i,j);
        ans.push_back(ret);
      }
    }
  sort(ans.begin(),ans.end());
  printf("%d\n",ct);
  for(int i=0; i<(int)ans.size(); ++i)
    printf("%d\n",ans[i]);
}
