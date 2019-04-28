#include <cstdio>
using namespace std;

int main()
{
  int t,p,q;
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    scanf("%d %d",&p,&q);
    printf("#%d %d %d\n",tc,p/q,p%q);
  }
}
