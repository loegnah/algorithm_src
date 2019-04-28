#include <cstdio>
using namespace std;

int main()
{
  int t,n,m;
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    scanf("%d %d",&n,&m);
    printf("#%d %d %d\n",tc,m-(n-m),n-m);
  }
}
