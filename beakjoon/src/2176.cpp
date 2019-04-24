#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int n,m;
int eny,enx;
char miro[102][102];
int c[102][102];
int cy[4] = {-1,0,1,0};
int cx[4] = {0,1,0,-1};

int bfs()
{
  queue<int> qy, qx;
  qy.push(0), qx.push(0);
  c[0][0] = 1;
  while(!qy.empty()) {
    int y = qy.front(); qy.pop();
    int x = qx.front(); qx.pop();
    if(y == eny && x == enx) return c[y][x];
    for(int i=0; i<4; ++i) {
      int ny = y + cy[i], nx = x + cx[i];
      if(ny < 0 || ny>=n || nx < 0 || nx >= m
        || miro[ny][nx] == '0' || c[ny][nx] != -1) continue;
      c[ny][nx] = c[y][x]+1;
      qy.push(ny); qx.push(nx);
    }
  }
}

int main()
{
  scanf("%d %d",&n,&m);
  for(int i=0; i<n; ++i)
    scanf("%s",miro[i]);
  eny = n-1;
  enx = m-1;
  memset(c,-1,sizeof c);
  printf("%d",bfs());
}
