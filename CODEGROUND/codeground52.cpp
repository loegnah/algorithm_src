#include <cstdio>
#include <cstring>
using namespace std;

const int MIN_INT = -987654321;
int t,n,ipt;
int arr[102][102];

int main()
{
  setbuf(stdout,NULL);
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    scanf("%d",&n);
    memset(arr,0,sizeof arr);
    for(int y=1; y<=n; ++y)
      for(int x=1; x<=n; ++x) {
        scanf("%d",&ipt);
        arr[y][x] = ipt + arr[y-1][x] + arr[y][x-1] - arr[y-1][x-1];
      }

    int mx = MIN_INT, comp;
    for(int y=1; y<=n; ++y)
      for(int x=1; x<=n; ++x)
        for(int py=0; py<y; ++py)
          for(int px=0; px<x; ++px) {
            comp = arr[y][x] - arr[y][px] - arr[py][x] + arr[py][px];
            mx = (mx>comp) ? mx : comp;
          }
    printf("Case #%d\n%d\n",tc,mx);
  }
}
