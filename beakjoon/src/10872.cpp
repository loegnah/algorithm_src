#include <cstdio>
using namespace std;

int main()
{
  int a, facto = 1;
  scanf("%d",&a);
  for(int i=2; i<=a; ++i) facto *= i;
  printf("%d",facto);
}
