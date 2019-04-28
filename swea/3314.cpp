#include <cstdio>
using namespace std;

const int ST_NUM = 5;

int main()
{
  int t,sc;
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    int avg = 0;
    for(int i=0; i<ST_NUM; ++i) {
      scanf("%d",&sc);
      avg += (sc<40) ? 40:sc;
    }
    printf("#%d %d\n",tc,avg/ST_NUM);
  }
}
