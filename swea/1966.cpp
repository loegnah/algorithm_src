#include <cstdio>
#include <algorithm>
using namespace std;

int arr[50];

int main()
{
  int t,n;
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    scanf("%d",&n);
    for(int i=0; i<n; ++i) scanf("%d",arr+i);
    sort(arr,arr+n);

    printf("#%d ",tc);
    for(int i=0; i<n; ++i) printf("%d ",arr[i]);
    printf("\n");
  }
}
