#include <cstdio>
using namespace std;

int board[9][9];
int cy[9] = {0,0,0,3,3,3,6,6,6};
int cx[9] = {0,3,6,0,3,6,0,3,6};

int solve()
{
  unsigned int ck;
  for(int y=0; y<9; ++y) {
    ck = 0;
    for(int x=0; x<9; ++x) {
      if(ck & (1<<board[y][x])) return 0;
      ck |= (1<<board[y][x]);
    }
  }
  for(int x=0; x<9; ++x) {
    ck = 0;
    for(int y=0; y<9; ++y) {
      if(ck & (1<<board[y][x])) return 0;
      ck |= (1<<board[y][x]);
    }
  }
  for(int i=0; i<9; ++i) {
    ck = 0;
    for(int j=0; j<9; ++j) {
      int y = cy[i]+cy[j]/3, x = cx[i]+cx[j]/3;
      if(ck & (1<<board[y][x])) return 0;
      ck |= (1<<board[y][x]);
    }
  }
  return 1;
}

int main()
{
  int t;
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    for(int i=0; i<9; ++i)
      for(int j=0; j<9; ++j)
        scanf("%d",&board[i][j]);
    printf("#%d %d\n",tc,solve());

  }
}
