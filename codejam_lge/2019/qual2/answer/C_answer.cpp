#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>
 
using ll = long long;
using pii = std::pair<int, int>;
 
using namespace std;
 
void solve() {
    ll n, current_cash, cost, profit_goal;
    cin >> n >> current_cash >> cost >> profit_goal;
 
    ll can_have = cost ? current_cash / cost : n;
 
    vector<ll> profit(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> profit[i];
        profit[i] -= cost;
 
        // making cumulative
        profit[i] += profit[i - 1];
        
        cout << profit[i] << " ";
    }
    cout << "\n";

 
    pii best = {n + 1, 0};
    deque<ll> dq;
    for (int i = 0; i <= n; ++i) {
        while (!dq.empty() && profit[i] <= profit[dq.back()]) dq.pop_back();
 
        while (!dq.empty() && profit[i] >= profit[dq.front()] + profit_goal) {
            int l = dq.front();
            dq.pop_front();
            best = min(best, pii(i-l, -l));
        }
 
        dq.push_back(i);
    }
 
    if (best.first > can_have) {
        cout << -1 << endl;
    } else {
        cout << -best.second + 1 << " " << -best.second + best.first << endl;
    }
}
 
int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tcs;
    cin >> tcs;
 
    while (tcs-- > 0) solve();
}