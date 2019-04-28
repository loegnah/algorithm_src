#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
  int t,sc,count[101];
  for(int tc=1; tc<=10; ++tc) {
    scanf("%d",&t);
    memset(count, 0, sizeof count);
    for(int i=0; i<1000; ++i) {
      scanf("%d",&sc);
      count[sc]++;
    }

    int mx_count = -1, mx_score = 0;
    for(int i=0; i<=100; ++i) {
      if(mx_count <= count[i]) {
        mx_count = count[i];
        mx_score = i;
      }
    }
    printf("#%d %d\n",tc,mx_score);
  }
}
