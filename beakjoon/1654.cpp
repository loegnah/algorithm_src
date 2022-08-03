#include <iostream>
#include <limits>
using namespace std;

int K, N;
long long lens[10005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> K >> N;
    for(int i=0; i<K; ++i) cin >> lens[i];

    long long lo = 0, hi = 3000000000;
    while(lo+1 < hi) {
        long long mid = (lo+hi)/2LL;
        int cnt = 0;

        for(int i=0; i<K; ++i) cnt += lens[i]/mid;
        
        if(cnt >= N) lo = mid;
        else hi = mid;
    }
    cout << lo << '\n';
}