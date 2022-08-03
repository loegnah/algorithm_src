#include <cstdio>
using namespace std;

inline int _max(const int a, const int b) {return a>b?a:b;}

int main()
{
    int N,t,p;
    int arr[17] = {0};

    scanf("%d",&N);
    for(int day=1; day<=N; ++day) {
        scanf("%d %d",&t,&p);
        arr[day] = _max(arr[day-1],arr[day]);
        if(day+t-1 <= N) arr[day+t] = _max(arr[day+t],arr[day]+p);
    }
    arr[N+1] = _max(arr[N],arr[N+1]);
    printf("%d\n",arr[N+1]);
}
