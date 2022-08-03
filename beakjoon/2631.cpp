// LIS

#include <cstdio>
#include <vector>
using namespace std;

int main()
{
  int n,child;
  scanf("%d",&n);

  vector<int> v;
  scanf("%d",&child);
  v.push_back(child);
  for(int i=2; i<=n; ++i) {
    scanf("%d",&child);
    if(v.back() < child) {
      v.push_back(child);
      continue;
    }
    for(int k=0; k<v.size(); ++k) {
      if(v[k] > child) {
        v[k] = child;
        break;
      }
    }
  }
  printf("%d",n-v.size());
}
