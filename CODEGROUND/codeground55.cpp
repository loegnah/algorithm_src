#include <cstdio>
using namespace std;

int t,n;

void trace_move(int bottom, int a, int b, int k)
{
  if(bottom < 1) return;
  trace_move(bottom-1,a,6-a-b,k);
  printf("%d -> %d\n",a,b);
  if(bottom != k) trace_move(bottom-1,6-a-b,b,k);
  else trace_move(bottom-1,6-a-b,b,--k);
}

int main()
{
  setbuf(stdout,NULL);
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    scanf("%d",&n);
    printf("Case #%d\n",tc);
    trace_move(n,1,3,n);
  }
}
