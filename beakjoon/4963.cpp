#include <cstdio>
#include <cstring>
using namespace std;

int cy[8] = {-1,-1,-1,0,1,1,1,0};
int cx[8] = {-1,0,1,1,1,0,-1,-1};
int w,h,board[52][52];
bool isVisit[52][52];

void check(int y, int x)
{
  if(y<0 || x<0 || y>=h || x>=w || isVisit[y][x] || !board[y][x]) return;
  isVisit[y][x] = true;
  for(int i=0; i<8; ++i) check(y+cy[i],x+cx[i]);
}


int main()
{
  while(1) {
    scanf("%d %d",&w,&h);
    if(w==0) return 0;
    for(int y=0; y<h; ++y)
      for(int x=0; x<w; ++x)
        scanf("%d",&board[y][x]);
    memset(isVisit,0,sizeof isVisit);
    int ans = 0;
    for(int y=0; y<h; ++y)
      for(int x=0; x<w; ++x) {
        if(board[y][x] && !isVisit[y][x]) {
          check(y,x);
          ans++;
        }
      }
    printf("%d\n",ans);
  }
}
