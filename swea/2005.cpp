#include <cstdio>
using namespace std;

int main()
{
  int t,tc,n,arr[2][11];
  for(scanf("%d",&t),tc=1; tc<=t; ++tc) {
    scanf("%d",&n);
    printf("#%d\n",tc);
    for(int h=1; h<=n; ++h) {
      int th = h%2;
      arr[th][1] = 1;
      for(int w=2; w<h; ++w) arr[th][w] = arr[1-th][w-1] + arr[1-th][w];
      arr[th][h] = 1;
      for(int i=1; i<=h; ++i) printf("%d ",arr[th][i]);
      printf("\n");
    }
  }
}
