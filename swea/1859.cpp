#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

int ipt[1000002];
vector<pair<int,int> > v(1000002);

int main()
{
  int t,n;
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    int sz = 0;

    scanf("%d",&n);
    for(int i=0; i<n; ++i) {
      scanf("%d",ipt+i);
      while(sz && (ipt[i]>=v[sz-1].second)) sz--;
      v[sz++] = make_pair(i,ipt[i]);
    }
    long long ans = 0, cur = 0;
    for(int i=0; i<sz; ++i) {
      int idx = v[i].first, num = v[i].second;
      for(; cur<= idx; ++cur) ans += (num-ipt[cur]);
    }
    printf("#%d %lld\n",tc,ans);
  }
}
