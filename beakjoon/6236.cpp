#include <iostream>
using namespace std;

int n,m;
long long pay[100005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<n; ++i) cin >> pay[i];
    
    int payMx = 0;
    for(int i=0; i<n; ++i)
        if(payMx < pay[i]) payMx = pay[i]; 

    long long lo = payMx-1, hi = 100000*10000;

    while(lo+1 < hi) {
        long long mid = (lo+hi)/2;
        long long curMoney = 0;
        int cnt = m;

        for(int i=0; i<n; ++i) {
            if(curMoney < pay[i]) {
                --cnt;
                curMoney = mid;
            }
            curMoney -= pay[i];
        }

        if(cnt < 0) lo = mid;
        else hi = mid;
    }

    cout << hi << "\n";
}