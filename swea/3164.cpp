#include <cstdio>
#include <cstring>
using namespace std;

char A[10005], B[105];

int main()
{
	int T;
    scanf("%d",&T);
	for (int tc = 1; tc <= T; ++tc) {
        scanf("%s %s",A,B);

        int A_len = strlen(A);
        int B_len = strlen(B);

        int count = 0,i=0,j=0;
        while(i<A_len) {
            count++;
            if(A[i]==B[0]) {
                j=1;
                while(i+j<A_len && j<B_len && A[i+j]==B[j]) j++;
                if(j==B_len) {
                    i+=B_len;
                    continue;
                }
            }
            i++;
        }

        printf("#%d %d\n",tc,count);
	}
}
