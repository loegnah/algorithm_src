#include <cstdio>
using namespace std;

int main()
{
  int n,m,ans=0;
  int arr[10] = {0,0,0,0,0,0,0,0,0,0};
  scanf("%d",&n);
  if(n==0) {
    printf("1");
    return 0;
  }
  while(n) {
    m = n%10;
    n /= 10;
    arr[m] += 1;
  }
  arr[6] = (arr[6]+arr[9]+1)/2;
  for(int i=0; i<9; ++i)
    ans = (arr[i] > ans ? arr[i] : ans);
  printf("%d",ans);
}
