#include <cstdio>
using namespace std;

char cache[100002];

int main()
{
  int n;
  scanf("%d",&n);
  for(int i=0; i<n; ++i) cache[i] = '#';
  cache[n] = '\0';
  printf("%s",cache);
}
