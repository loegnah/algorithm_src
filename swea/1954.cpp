#include <cstdio>
using namespace std;

const int py[4] = {0,0,1,1}, px[4] = {0,1,1,0};
int arr[11][11],num;

void fill_arr(int len,int sy, int sx)
{
  int i;
  for(i=0; i<len; ++i) arr[sy][sx+i] = num++;
  for(i=0; i<len; ++i) arr[sy+i][sx+len] = num++;
  for(i=0; i<len; ++i) arr[sy+len][sx+len-i] = num++;
  for(i=0; i<len; ++i) arr[sy+len-i][sx] = num++;
}

int main()
{
  int T,N;
  scanf("%d",&T);
  for(int TC=1; TC<=T; ++TC) {
    scanf("%d",&N);

    int sy = 0, sx = 0;
    num = 1;
    for(int len=N-1; len>0; len-=2)
      fill_arr(len,sy++,sx++);
    if(N%2) arr[N/2][N/2] = N*N;

    printf("#%d\n",TC);
    for(int y=0; y<N; ++y) {
      for(int x=0; x<N; ++x) printf("%d ",arr[y][x]);
      printf("\n");
    }
  }
}
