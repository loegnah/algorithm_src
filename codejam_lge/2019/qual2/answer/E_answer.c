#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <set>
using namespace std;
int match(int n, int m, vector<int> &x, vector<int> &y, vector<int> &z) {
        multiset<int> ms(x.begin(), x.end());
        vector<int> idx(m);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) {
                if (z[i] != z[j])
                        return z[i] < z[j];
                return y[i] < y[j];
        });
        int ans = 0;
        for (auto i : idx) {
                auto it = ms.lower_bound(y[i]);
                if (it == ms.end() || *it > z[i])
                        continue;
                ++ans;
                ms.erase(it);
        }
        return ans;
}
int main(void) {
        cout.sync_with_stdio(false);
        cin.tie(nullptr);
        int nTests;
        cin >> nTests;
        while (nTests--) {
                int n, m;
                cin >> n >> m;
                vector<int> x(n);
                for (int i = 0; i < n; ++i)
                        cin >> x[i];
                vector<int> y(m), z(m);
                for (int i = 0; i < m; ++i)
                        cin >> y[i] >> z[i];
                cout << match(n, m, x, y, z) << '\n';
        }
        return 0;
}