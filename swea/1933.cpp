#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n,i;
  vector<int> ans;
  scanf("%d",&n);
  for(i=1; i*i<n; ++i) {
    if(n%i==0) {
      ans.push_back(i);
      ans.push_back(n/i);
    }
  }
  if(n%i==0) ans.push_back(i);
  sort(ans.begin(),ans.end());
  for(int i=0; i<ans.size(); ++i) {
    printf("%d ",ans[i]);
  }
}
