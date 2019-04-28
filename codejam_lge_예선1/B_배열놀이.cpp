#include <cstdio>
using namespace std;

int N,M;
int arr[1005][1005], rowSum[1005], colSum[1005];

void input()
{
    scanf("%d %d",&N, &M);
    for(int y=1; y<=N; ++y) for(int x=1; x<=N; ++x)
        scanf("%d",&arr[y][x]);
}

void lineSum()
{
    for(int y=1; y<=N; ++y) {
        int& rsy = rowSum[y]; 
        rsy = 0;
        for(int x=1; x<=N; ++x) rsy += arr[y][x]; 
    }

    for(int x=1; x<=N; ++x) {
        int& csy = colSum[x]; 
        csy = 0;
        for(int y=1; y<=N; ++y) csy += arr[y][x]; 
    }
}

void solve()
{
    int r1,c1,r2,c2,v;
    for(int i=0; i<M; ++i) {
        scanf("%d %d %d %d %d",&r1,&c1,&r2,&c2,&v);
        int dr = r2-r1+1, dc = c2-c1+1;

        for(int y=r1; y<=r2; ++y) rowSum[y] += dc*v;
        for(int x=c1; x<=c2; ++x) colSum[x] += dr*v;
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--) {
        input();
        lineSum();
        solve();

        for(int y=1; y<=N; ++y) printf("%d ",rowSum[y]);
        printf("\n");
        for(int x=1; x<=N; ++x) printf("%d ",colSum[x]);
        printf("\n");
           
    }
}