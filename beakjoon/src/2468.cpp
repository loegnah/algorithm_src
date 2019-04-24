#include <cstdio>
#include <cstring>
using namespace std;

int N;
int loc[102][102] = {-1};
bool isVst[102][102];
int cy[4] = {-1,0,1,0}, cx[4] = {0,1,0,-1};
int nx,ny;

void dfs(int y, int x, int h)
{
  isVst[y][x] = true;
  for(int i=0; i<4; ++i) {
    nx = x + cx[i]; ny = y + cy[i];
    if(!isVst[ny][nx] && loc[ny][nx]>h) dfs(ny,nx,h);
  }
}

int main()
{

  scanf("%d",&N);
  for(int i=1; i<N+1; ++i)
   for(int j=1; j<N+1; ++j)
    scanf("%d",&loc[i][j]);
  for(int y=0; y<N+2; ++y) loc[y][0] = loc[y][N+1] = 111;
  for(int x=0; x<N+2; ++x) loc[0][x] = loc[N+1][x] = 111;

  int ans = 1;
  for(int i=1; i<101; ++i) {
    memset(isVst,0,sizeof isVst);
    for(int y=0; y<N+2; ++y) isVst[y][0] = isVst[y][N+1] = true;
    for(int x=0; x<N+2; ++x) isVst[0][x] = isVst[N+1][x] = true;
    int tmp = 0;
    for(int y=1; y<N+1; ++y)
      for(int x=1;x<N+1; ++x)
        if(loc[y][x]<=i)
          isVst[y][x] = true;
    for(int y=1; y<N+1; ++y)
      for(int x=1; x<N+1; ++x)
        if(!isVst[y][x]) {
          dfs(y,x,i);
          ++tmp;
        }
    ans = ans > tmp ? ans : tmp;
  }
  printf("%d",ans);
}
