#include <cstdio>
#include <algorithm>
using namespace std;

int pre[1005];

int main()
{
  int w,ans,mx;
  for(int tc=1; tc<=10; ++tc) {
    scanf("%d",&w);
    for(int i=0; i<w; ++i) scanf("%d",pre+i);

    ans = 0;
    for(int i=2; i<w-2; ++i) {
      mx = max(max(pre[i-2],pre[i-1]),max(pre[i+1],pre[i+2]));
      if(mx<pre[i]) ans += pre[i]-mx;
    }
    printf("#%d %d\n",tc,ans);
  }
}
