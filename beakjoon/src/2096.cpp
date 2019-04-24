#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
  int N, cur, pre;
  int mx[2][3] = {0}, mn[2][3] = {0}, arr[3];
  scanf("%d",&N);
  while(N--) {
      scanf("%d %d %d",&arr[0], &arr[1], &arr[2]);
      cur = N%2;
      pre = (N+1)%2;
      mx[cur][0] = max(mx[pre][0],mx[pre][1]) + arr[0];
      mx[cur][1] = max(mx[pre][0],max(mx[pre][1],mx[pre][2])) + arr[1];
      mx[cur][2] = max(mx[pre][1],mx[pre][2]) + arr[2];
      mn[cur][0] = min(mn[pre][0],mn[pre][1]) + arr[0];
      mn[cur][1] = min(mn[pre][0],min(mn[pre][1],mn[pre][2])) + arr[1];
      mn[cur][2] = min(mn[pre][1],mn[pre][2]) + arr[2];
  }
  int ans1 = max(mx[cur][0], max(mx[cur][1],mx[cur][2]));
  int ans2 = min(mn[cur][0], min(mn[cur][1],mn[cur][2]));
  printf("%d %d",ans1,ans2);
}
