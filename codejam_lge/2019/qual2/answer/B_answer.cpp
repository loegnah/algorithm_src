#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
 
bool isPossible(int n) {
    int cnt = 0;
    while (n > 0) {
        cnt += (n % 10) % 2;
        n /= 10;
    }
    return cnt % 2 == 1;
}
int main() {
    int t, n, temp;
    cin >> t;
    while (t--) {
        cin >> n;
        int totalSum = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            cin >> temp;
            totalSum += temp;
            mp[temp]++;
        }
        vector<long long> dp(totalSum + 1, 0);
        for (auto iter : mp) {
            for (int i = totalSum; i >= 0; i--) {
                if (dp[i] > 0) {
                    long long add = dp[i];
                    for (int cnt = 1; cnt <= iter.second; cnt++)
                        dp[i + iter.first * cnt] += add;
                }
            }
            for (int cnt = 1; cnt <= iter.second; cnt++)
                dp[iter.first * cnt] += 1;
        }
        long long ret = 0;
        for (int j = totalSum; j > 0; j--) {
            if (dp[j] > 0 && isPossible(j)) {
                ret += dp[j];
            }
        }
        cout << ret << endl;
    }
    return 0;
}