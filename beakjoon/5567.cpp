#include <cstdio>
#include <vector>
using namespace std;

vector<int> fnd[503];
bool invited[503];

int solve()
{
  int ans = 0;
  vector<int> q;
  invited[1] = true;
  for(int f : fnd[1]) {
    q.push_back(f);
    invited[f] = true;
    ans++;
  }
  for(int f : q)
    for(int f2 : fnd[f])
      if(!invited[f2]) {
        invited[f2] = true;
        ans++;
      }
  return ans;
}

int main()
{
  int n,m,a,b;
  scanf("%d",&n);
  scanf("%d",&m);
  for(int i=1; i<=n; ++i) {
    fnd[i].clear();
    invited[i] = false;
  }
  for(int i=0; i<m; ++i) {
    scanf("%d %d",&a,&b);
    fnd[a].push_back(b);
    fnd[b].push_back(a);
  }
  printf("%d",solve());
}
