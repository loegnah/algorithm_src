#include <cstdio>
#include <cstring>
using namespace std;

int N, dst[20][20];
bool isUsed[103];

int _max(int a, int b) { return a>b?a:b; }

bool overlap_check(int y,int x,int lf,int rt)
{
    memset(isUsed,0,sizeof isUsed);

    for(int i=0; i<=lf; ++i) {
        int n1 = dst[y+i][x-i], n2 = dst[y+rt+i][x+rt-i];
        if(isUsed[n1]) return false;
        isUsed[n1] = true;
        if(isUsed[n2]) return false;
        isUsed[n2] = true;
    }

    for(int i=1; i<rt; ++i) {
        int n1 = dst[y+i][x+i], n2 = dst[y+lf+i][x-lf+i];
        if(isUsed[n1]) return false;
        isUsed[n1] = true;
        if(isUsed[n2]) return false;
        isUsed[n2] = true;
    }
    return true;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int TC=1; TC<=T; ++TC)
    {
        scanf("%d",&N);
        for(int y=0; y<N; ++y)
            for(int x=0; x<N; ++x)
                scanf("%d",&dst[y][x]);

        int ans = -1;

        for(int y=0; y<N-2; ++y)
            for(int x=1; x<N-1; ++x)
                for(int lf=1; x-lf>=0 && y+lf<N-1; ++lf)
                    for(int rt=1; x+rt<N && y+lf+rt<N; ++rt)
                        if(overlap_check(y,x,lf,rt)) ans = _max(ans,lf*2+rt*2);

        printf("#%d %d\n",TC,ans);
    }
}
