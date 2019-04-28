#include <cstdio>
using namespace std;

const int MXN = 100;
const int QSIZE = MXN*MXN;
const int NONREACH = -1;

int st,qb,qe;
int adj[MXN+5][MXN+5], al[MXN+5], dst[MXN+5], qu[QSIZE][2];

void bfs()
{
    qb = 0; qe = 0;
    qu[qe][0] = st; qu[qe++][1] = 0;
    while(qb != qe) {
        int m = qu[qb][0];
        int d = qu[qb][1];
        qb = (qb+1)%QSIZE;

        if(dst[m] != -1) continue;
        dst[m] = d;

        for(int i=0; i<al[m]; ++i) {
            int nxt = adj[m][i];
            if(dst[nxt] == -1 || dst[nxt]>d+1) {
                qu[qe][0] = nxt;
                qu[qe][1] = d+1;
                qe = (qe+1)%QSIZE;
            }
        }
    }
}

int main()
{
    int n,from,to;
    setbuf(stdout,NULL);

    for(int tc=1; tc<=10; ++tc) {
        scanf("%d %d",&n,&st);

        for(int i=1; i<=MXN; ++i) {
            al[i] = 0;
            dst[i] = NONREACH;
        }

        for(int i=0; i<n/2; ++i) {
            scanf("%d %d",&from,&to);
            adj[from][al[from]++] = to;
        }

        bfs();

        int mx_dst = NONREACH, mx_node = -1;
        for(int i=1; i<=MXN; ++i) {
            if(dst[i] > mx_dst) {mx_dst = dst[i]; mx_node = i;}
            else if(dst[i]==mx_dst && i>mx_node) mx_node = i;
        }

        printf("#%d %d\n",tc,mx_node);
    }
}
