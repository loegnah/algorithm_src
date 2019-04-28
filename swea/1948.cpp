#include <cstdio>
using namespace std;

const int lastDay[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

int main()
{
  int t,ma,mb,da,db;
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    scanf("%d %d %d %d",&ma,&da,&mb,&db);
    --ma; --mb;
    int ans = 0;
    if(ma==mb) ans = db-da+1;
    else {
      ans += lastDay[ma++]-da+1;
      while(ma<mb) ans += lastDay[ma++];
      ans += db;
    }
    printf("#%d %d\n",tc,ans);
  }
}
