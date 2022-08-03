#include <cstdio>
#include <algorithm>
using namespace std;

int N;
int sck[2][100003];
int m[2][100003];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--) {
	scanf("%d",&N);
	for(int i=0; i<N; ++i) scanf("%d",&sck[0][i]);
	for(int i=0; i<N; ++i) scanf("%d",&sck[1][i]);
	m[0][0] = sck[0][0];
	m[1][0] = sck[1][0];
	if(N==1) {
	    printf("%d\n",max(m[0][0],m[1][0]));
	    continue;
	}
	m[0][1] = max(m[0][0], m[1][0]+sck[0][1]);
	m[1][1] = max(m[1][0], m[0][0]+sck[1][1]);
	for(int i=2; i<N; ++i) {
	    for(int j=0; j<2; ++j) {
		int k = (j+1)%2;
		m[j][i] = max(m[j][i-1],
			max(m[k][i-1]+sck[j][i],
			    m[k][i-2]+sck[j][i]));
	    }
	}
	printf("%d\n",max(m[0][N-1],m[1][N-1]));
    }
}
