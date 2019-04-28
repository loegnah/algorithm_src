#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

priority_queue<int> heap;
vector<int> ans;

int main()
{
  int t,n,op,num;
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    scanf("%d",&n);

    heap = priority_queue<int>();
    ans.clear();

    for(int i=0; i<n; ++i) {
      scanf("%d",&op);
      if(op==1) {
        scanf("%d",&num);
        heap.push(num);
      }
      else if(op==2) {
        if(heap.empty()) ans.push_back(-1);
        else {
          ans.push_back(heap.top());
          heap.pop();
        }
      }
    }
    printf("#%d ",tc);
    for(int i=0; i<ans.size(); ++i) printf("%d ",ans[i]);
    printf("\n");
  }
}
