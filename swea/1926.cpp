#include <cstdio>
using namespace std;

int main()
{
  int n;
  scanf("%d",&n);
  for(int i=1; i<=n; ++i) {
    int count = 0, tmp = i;
    while(tmp) {
      int tmp2 = tmp%10;
      if(tmp2 && (tmp2%3==0)) count++;
      tmp /= 10;
    }
    if(count==0) printf("%d ",i);
    else {
      while(count--) printf("-");
      printf(" ");
    }
  }
}
