#include <cstdio>
#include <algorithm>
using namespace std;

long long arr[10005];

int main()
{
  int t,n;
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    scanf("%d",&n);
    for(int i=0; i<n; ++i) scanf("%lld",&arr[i]);
    sort(arr,arr+n);
    long long ans = 0;
    for(int i=0; i<n; i+=2) ans += arr[i];
    for(int i=1; i<n; i+=2) ans -= arr[i];
    printf("Case #%d\n%lld\n",tc,ans); 
  }
}
