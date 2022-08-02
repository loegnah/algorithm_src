#include <cstdio>
using namespace std;

double a[500001]={0.0, 2.920050977316};

int nth_sosu(int n) {
    for(int i=2; i<=n; i++)
 		a[i]=((int)a[i-1])*(a[i-1]-((int)a[i-1])+1.0);
	return a[n];
}

int main(void)
{
    int n;

    scanf("%d" ,&n);
    printf("%d" ,nth_sosu(n));
    
	return 0;
}
