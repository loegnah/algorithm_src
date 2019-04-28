#include <cstdio>
using namespace std;

char board[10][10];
int lu[4],rd[4];

int main()
{
  int len,tmp,i,y,x,ans;
  bool ck;

  for(int tc=1; tc<=10; ++tc) {
    scanf("%d",&len);
    for(i=0; i<8; ++i) scanf("%s",board[i]);
    tmp = 1-(len%2);
    for(i=0; i<len/2; ++i) {
      lu[i] = -(i+1)+tmp;
      rd[i] = i+1;
    }
    ans = 0;

    for(y=0; y<8; ++y) {
      for(x=(len-1)/2; x<8-len/2; ++x) {
        ck = true;
        for(i=0; i<len/2; ++i)
          if(board[y][x+lu[i]] != board[y][x+rd[i]]) {
            ck = false;
            break;
          }
        if(ck) ans++;
      }
    }

    for(int x=0; x<8; ++x) {
      for(y=(len-1)/2; y<8-len/2; ++y) {
        ck = true;
        for(i=0; i<len/2; ++i)
          if(board[y+lu[i]][x] != board[y+rd[i]][x]) {
            ck = false;
            break;
          }
        if(ck) ans++;
      }
    }
    printf("#%d %d\n",tc,ans);
  }
}
