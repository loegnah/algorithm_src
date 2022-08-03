#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int T,L;
int stt[2], edd[2];
int cy[8] = {2,1,-1,-2,-2,-1,1,2};
int cx[8] = {1,2,2,1,-1,-2,-2,-1};
bool ck[301][301];
int c[301][301];

int bfs()
{
  queue<int> qy;
  queue<int> qx;
  qy.push(stt[0]);
  qx.push(stt[1]);
  c[stt[0]][stt[1]] = 0;

  while(!qy.empty()) {
    int y = qy.front(); qy.pop();
    int x = qx.front(); qx.pop();
    if(y == edd[0] && x == edd[1]) return c[y][x];
    for(int i=0; i<8; ++i) {
      int ny = y+cy[i];
      int nx = x+cx[i];
      if(ny<0 || ny>=L || nx<0 || nx>=L || c[ny][nx] != -1) continue;
      c[ny][nx] = c[y][x]+1;
      qy.push(ny);
      qx.push(nx);
    }
  }
}

int main()
{
  scanf("%d",&T);
  while(T--) {
    memset(ck,0,sizeof ck);
    memset(c,-1,sizeof c);
    scanf("%d",&L);
    scanf("%d %d",stt, stt+1);
    scanf("%d %d",edd, edd+1);
    printf("%d\n",bfs());
  }
}
