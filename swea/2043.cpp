#include <cstdio>
using namespace std;

int main()
{
  int a,b;
  scanf("%d %d",&a,&b);
  a = a-b;
  if(a<0) a*=-1;
  printf("%d",a+1);
}
