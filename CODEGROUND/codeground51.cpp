#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

const int MX_INT = 987654321;

int t,n,m;
vector<pair<int,pair<int,int> > > edge;
vector<int> parent(1002,0);

int find_p(int a) {
  return (a==parent[a]) ? a : (parent[a]=find_p(parent[a]));
}

int solve()
{
  for(int i=1; i<=n; ++i) parent[i] = i;
  sort(edge.begin(),edge.end());

  int count = 0;
  for(int i=0; i<m; ++i) {
    int a = edge[i].second.first, b = edge[i].second.second;
    int c = edge[i].first;
    int pa = find_p(a) , pb = find_p(b);
    if(pa != pb) {
      parent[pb] = pa;
      count++;
      if(count == n/2) return c;
    }
  }
}

int main(int argc,char** argv)
{
  setbuf(stdout,NULL);
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    edge.clear();
    scanf("%d %d",&n,&m);
    int s,t,c;
    for(int i=0; i<m; ++i) {
      scanf("%d %d %d",&s,&t,&c);
      edge.push_back(make_pair(c,make_pair(s,t)));
    }
    printf("Case #%d\n%d\n",tc,solve());
  }
  return 0;
}
