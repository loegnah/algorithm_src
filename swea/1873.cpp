#include <cstdio>
using namespace std;

const char TANK[5] = "<^>v";
const char DRCtoCMD[5] = "LURD";

int h,w,n,y,x,drc;
char board[21][21];
char input[101];
int move_cmd['Z'-'A'+1][3];

void tank_loc()
{
  for(int i=0; i<h; ++i)
    for(int j=0; j<w; ++j)
      for(int u=0; u<4; ++u)
        if(board[i][j] == TANK[u]) {
          y = i;
          x = j;
          drc = u;
          return;
        }
}

bool isWithin(int ty, int tx)
{
  return (ty>=0 && ty<h && tx>=0 && tx<w);
}

void shoot()
{
  int cy = move_cmd[DRCtoCMD[drc]][0], cx = move_cmd[DRCtoCMD[drc]][1];
  int ty = y+cy, tx = x+cx;
  while(isWithin(ty,tx)) {
    if(board[ty][tx]=='#') return;
    if(board[ty][tx]=='*') {
      board[ty][tx] = '.';
      return;
    }
    ty += cy;
    tx += cx;
  }
}

bool check(char cmd)
{
  drc = move_cmd[cmd][2];
  board[y][x] = TANK[drc];

  int ny = y+move_cmd[cmd][0], nx = x+move_cmd[cmd][1];
  if(isWithin(ny,nx)) return board[ny][nx]=='.';
  else return false;
}

void move(char cmd)
{
  board[y][x] = '.';
  y += move_cmd[cmd][0];
  x += move_cmd[cmd][1];
  board[y][x] = TANK[drc];
}

void solve()
{
  tank_loc();

  for(int i=0; i<n; ++i) {
    char cmd = input[i];

    if(cmd == 'S') shoot();
    else if(check(cmd)) move(cmd);
  }
}

void preSetting()
{
  move_cmd['L'][0]=0; move_cmd['L'][1]=-1; move_cmd['L'][2]=0;
  move_cmd['U'][0]=-1; move_cmd['U'][1]=0; move_cmd['U'][2]=1;
  move_cmd['R'][0]=0; move_cmd['R'][1]=1; move_cmd['R'][2]=2;
  move_cmd['D'][0]=1; move_cmd['D'][1]=0; move_cmd['D'][2]=3;
}

int main()
{
  int t;
  scanf("%d",&t);
  preSetting();
  for(int tc=1; tc<=t; ++tc) {
    scanf("%d %d",&h,&w);
    for(int i=0; i<h; ++i) scanf("%s",board[i]);
    scanf("%d",&n);
    scanf("%s",input);

    solve();

    printf("#%d ",tc);
    for(int i=0; i<h; ++i) printf("%s\n",board[i]);
  }
}
