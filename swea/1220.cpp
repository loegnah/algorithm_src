#include <cstdio>
using namespace std;

int line[105];
int len,tmp;

int main()
{
  for(int tc=1; tc<=10; ++tc) {
    scanf("%d",&len);

    int ans = 0;

    for(int x=0; x<len; ++x) line[x] = 0;
    for(int y=0; y<len; ++y) {
      for(int x=0; x<len; ++x) {
        scanf("%d",&tmp);
        if(tmp == 2) {
          ans += (line[x]==1 ? 1:0);
          line[x] = 0;
        }
        else if(tmp == 1) line[x] = 1;
      }
    }
    printf("#%d %d\n",tc,ans);

  }
}
