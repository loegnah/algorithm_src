#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

const int MX = 2000000009;

int N,M;
int A[1000005], B[1000005];

inline int _abs(int num) { return num>0 ? num:-num; }

void input()
{
    scanf("%d %d",&N, &M);

    for(int i=0; i<N; ++i) scanf("%d",A+i);
    for(int i=0; i<M; ++i) scanf("%d",B+i);
}

long long solve()
{
    sort(A,A+N);
    sort(B,B+M);
    B[M] = MX;

    long long ret = 0;

    for(int aIdx=0, bIdx=0; aIdx<N; ++aIdx) {
        int aaidx = A[aIdx];
        while(bIdx < M) {
            int db1 = _abs(aaidx-B[bIdx]);
            int db2 = _abs(aaidx-B[bIdx+1]);
            if(db1<=db2) break;
            ++bIdx;
        }
        ret += B[bIdx];
    }
    return ret;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--) {
        input();
        printf("%lld\n",solve());
    }
}