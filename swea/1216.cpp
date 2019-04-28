#include <cstdio>
#include <algorithm>
using namespace std;

const int SIZE = 100;
char board[105][105];

bool check(int y1,int x1, int y2, int x2)
{
  if(y1<0 || x1<0 || y2>=SIZE || x2>=SIZE) return false;
  return board[y1][x1] == board[y2][x2];
}

int main()
{
  int t,len,tmp,i,y,x,ans;
  bool ck;

  for(int tc=1; tc<=10; ++tc) {
    scanf("%d",&t);
    for(i=0; i<SIZE; ++i) scanf("%s",board[i]);

    ans = -1;
    for(y=0; y<SIZE; ++y) {
      for(x=0; x<SIZE; ++x) {
        for(i=1; check(y-i,x,y+i,x); ++i);
        ans = max(ans,2*i-1);
        for(i=1; check(y,x-i,y,x+i); ++i);
        ans = max(ans,2*i-1);
        for(i=1; check(y-i,x,y+i-1,x); ++i);
        ans = max(ans,2*i-2);
        for(i=1; check(y,x-i,y,x+i-1); ++i);
        ans = max(ans,2*i-2);
      }
    }
    printf("#%d %d\n",tc,ans);
  }
}
