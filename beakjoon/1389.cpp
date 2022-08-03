#include <iostream>
#include <cstring>
using namespace std;

const int MX = 987654321;

int dist[105][105];

int main()
{
    int userCnt, relCnt, a, b;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> userCnt >> relCnt;

    //init
    for(int i=1; i<=userCnt; ++i)
        for(int j=1; j<=userCnt; ++j)
            dist[i][j] = MX;
    
    //input
    while(relCnt--) {
        cin >> a >> b;
        dist[a][b] = dist[b][a] = 1;
    }

    //calc dist
    for(int k=1; k<=userCnt; ++k)
        for(int i=1; i<=userCnt; ++i)
            for(int j=1; j<=userCnt; ++j)
                if(dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    //calc answer
    int minDist = MX, ansUser = -1;
    for(int i=1; i<=userCnt; ++i) {
        int tmpDist = 0;
        for(int j=1; j<=userCnt; ++j) {
            if(i != j) tmpDist += dist[i][j];
        }
        if(tmpDist < minDist) {
            minDist = tmpDist;
            ansUser = i;
        }
    }
    cout << ansUser << '\n';

}