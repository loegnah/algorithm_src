#include <cstdio>
using namespace std;

int arr[1002];

int main()
{
  int t,n,len,k,idx;
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    scanf("%d",&n);

    len = 0; arr[0] = 0;
    for(int i=0; i<n; ++i) {
      scanf("%d",&k);
      if(arr[len]<=k) arr[++len] = k;
      else {
        idx = len-1;
        while(arr[idx]>k) --idx;
        arr[idx+1] = k;
      }
    }
    printf("#%d %d\n",tc,len);
  }
}
