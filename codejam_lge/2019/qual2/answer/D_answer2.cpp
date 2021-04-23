#include <iostream>
#include <vector>
using namespace std;
 
#define MAX_N   5000
#define MAX_M   1000000
 
long long score(int n, int m, vector<int> &x, vector<int> &y) {
    vector<int> cnt(n + 1);
    for (auto i : x)
        ++cnt[i];
    for (auto i : y)
        ++cnt[i];
    long long total = (long long)n * (n - 1) * (n - 2) / 6;
    long long deg = 0;
    for (int i = 1; i <= n; ++i)
        deg += (long long)cnt[i] * cnt[i];
    return total - (n - 1) * (long long)m + deg / 2;
}
 
int main(void) {
    cout.sync_with_stdio(false);
    cin.tie(nullptr);
    int nTests;
    cin >> nTests;
    while (nTests--) {
        int n, m;
        cin >> n >> m;
        vector<int> x(m), y(m);
        for (int i = 0; i < m; ++i)
            cin >> x[i] >> y[i];
        cout << score(n, m, x, y) << '\n';
    }
    return 0;
}