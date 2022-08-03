#include <iostream>
using namespace std;

int h[1000005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long m;

    cin >> n >> m;
    for(int i=0; i<n; ++i) cin >> h[i];

    int lo = 0, hi = 1000000001;

    while(lo+1 < hi) {
        int mid = (lo+hi)/2;
        long long sum = 0;

        for(int hh : h)
            if(hh > mid) sum += hh-mid;

        
        if(sum >= m) lo = mid;
        else hi = mid;
    }

    cout << lo << "\n";
}
