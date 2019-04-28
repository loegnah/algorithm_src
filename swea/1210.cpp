#include <cstdio>
using namespace std;

const int SIZE = 100;
int line[105], player[105], dst[105];

void swap_player(int a,int b) {
  dst[player[a]] += b-a;
  dst[player[b]] += b-a;
  int k = player[a];
  player[a] = player[b];
  player[b] = k;
}

int main()
{
  int t,tmp, y,x,count;
  for(int tc=1; tc<=10; ++tc) {
    scanf("%d",&t);

    for(x=0; x<SIZE; ++x) {
      scanf("%d",&line[x]);
      if(line[x]) {
        player[x] = x;
        dst[x] = 0;
      }
      else dst[x] = -1;
    }

    for(y=1; y<SIZE; ++y) {
      count = 0;
      for(x=0; x<SIZE; ++x) {
        scanf("%d",&line[x]);
        if(line[x]) count++;
        else {
          if(count>1) swap_player(x-count,x-1);
          count = 0;
        }
      }
      if(count>1) swap_player(x-count,x-1);
    }
    int ans =0, mn = 9999999;
    for(int x=0; x<SIZE; ++x){
      if(dst[x]>=0 && dst[x]<mn) {
        mn = dst[x];
        ans = x;
      }}

    printf("#%d %d\n",tc,ans);
  }
}
