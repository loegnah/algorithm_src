#include <cstdio>
using namespace std;

const int ALLFIND = (1<<10)-1;

void check(int& find, int num)
{
  while(num) {
    find |= (1<<(num%10));
    num /= 10;
  }
}

int main()
{
  int t,n;
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    scanf("%d",&n);

    int find = 0, idx = 0;
    while(find != ALLFIND) {
      idx++;
      check(find,n*idx);
    }
    printf("#%d %d\n",tc,idx*n);
  }
}
