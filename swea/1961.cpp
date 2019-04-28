#include <cstdio>
using namespace std;

int n,arr[8][8];

void linePrint(int k)
{
  int kk = n-k+1;
  for(int y=n; y>0; --y) printf("%d",arr[y][k]);
  printf(" ");
  for(int x=n; x>0; --x) printf("%d",arr[kk][x]);
  printf(" ");
  for(int y=1; y<=n; ++y) printf("%d",arr[y][kk]);
  printf("\n");
}


int main()
{
  int t;
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    scanf("%d",&n);
    for(int y=1; y<=n; ++y)
      for(int x=1; x<=n; ++x)
        scanf("%d",&arr[y][x]);

    printf("#%d\n",tc);
    for(int k=1; k<=n; ++k) linePrint(k);
  }
}
