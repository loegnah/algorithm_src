#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

struct mcr {
  int y,x,ct,drc;

  mcr() { y=x=ct=drc=0; }
  mcr(int _y,int _x, int _ct, int _drc) {
    y = _y; x = _x; ct = _ct ; drc = _drc;
  }
};

const int NOT = -1;
const int my[5] = {0,-1,1,0,0}, mx[5] = {0,0,0,-1,1};
const int changeDrc[5] = {0,2,1,4,3};

int n,m,k;
vector<int> board[103][103];
vector<mcr> mcrs;
vector<bool> valid;
vector<mcr>::iterator iter;

void input()
{
  int i,y,x,ct,drc;

  scanf("%d %d %d",&n,&m,&k);

  mcrs.clear();
  valid = vector<bool>(k,true);

  for(i=0; i<k; ++i) {
    scanf("%d %d %d %d",&y,&x,&ct,&drc);
    mcrs.push_back(mcr(y,x,ct,drc));
  }
}

void reset_board()
{
  for(int i=0; i<n; ++i)
    for(int j=0; j<n; ++j)
      board[i][j].clear();
}

void move_mcrs()
{
  int drc;
  for(int i = 0; i<mcrs.size(); ++i) {
    if(valid[i]) {
      drc = mcrs[i].drc;
      mcrs[i].y += my[drc];
      mcrs[i].x += mx[drc];
      board[mcrs[i].y][mcrs[i].x].push_back(i);
    }
  }
}

void boundary_check(int cy, int cx)
{
  int num;
  for(int j=0; j<board[cy][cx].size(); ++j) {
    num = board[cy][cx][j];
    mcrs[num].drc = changeDrc[mcrs[num].drc];
    mcrs[num].ct /= 2;
    if(mcrs[num].ct==0) valid[num] = false;
  }
}

void sum_check(int cy, int cx) {
  int num;
  if(board[cy][cx].size() >= 2) {
    int mx = -1, mxNum,sum=0;
    for(int j=0; j<board[cy][cx].size(); ++j) {
      num = board[cy][cx][j];
      valid[num] = false;
      sum += mcrs[num].ct;
      if(mx<mcrs[num].ct) {
        mx = mcrs[num].ct;
        mxNum = num;
      }
    }
    valid[mxNum] = true;
    mcrs[mxNum].ct = sum;
  }
}

void check()
{
  int i,j,num;

  for(i=0; i<n; ++i) {boundary_check(0,i); boundary_check(n-1,i);}
  for(i=1; i<n-1; ++i) {boundary_check(i,0); boundary_check(i,n-1);}

  for(i=1; i<n-1; ++i)
    for(j=1; j<n-1; ++j)
      sum_check(i,j);
}

void solve()
{
  int i,drc;

  for(int _time = 1; _time<=m; ++_time) {
    reset_board();
    move_mcrs();
    check();
  }
}

int calc_ans()
{
  int ans = 0;
  for(int i = 0; i<mcrs.size(); ++i)
    if(valid[i])
      ans += mcrs[i].ct;
  return ans;
}

int main()
{
  int t;
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    input();
    solve();
    printf("#%d %d\n",tc,calc_ans());
  }
}
