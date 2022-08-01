#include <algorithm>
#include <cstring>
#include <iostream>
#include <limits>
using namespace std;

long long MX = numeric_limits<long long>::max();
long long subSums[2005][2005];
long long rangePenalty[2005][2005];
int N, A, B, C, nums[2005];
long long MOD;
long long dp[2005][2005];
int KN[2005][2005];

int calc(int vi, int vj) {
  return (A * (vi ^ vj) + B * (vi & vj) + C * (vi | vj)) % MOD;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  while (T--) {
    cin >> N;
    cin >> A >> B >> C >> MOD;
    for (int i = 0; i < N; ++i) cin >> nums[i];
    memset(dp, 0, sizeof(dp));
    memset(KN, 0, sizeof(KN));

    if (N == 1) {
      cout << 0 << '\n';
      continue;
    }

    for (int i = 0; i < N; ++i) {
      subSums[i][i] = 0;
      for (int j = i + 1; j < N; ++j) {
        subSums[i][j] = subSums[i][j - 1] + calc(nums[i], nums[j]);
      }
    }

    for (int j = N - 1; j >= 0; --j) {
      rangePenalty[j][j] = subSums[j][j];
      for (int i = j - 1; i >= 0; --i) {
        rangePenalty[i][j] = rangePenalty[i + 1][j] + subSums[i][j];
      }
    }

    for (int i = 1; i < N + 1; ++i) KN[i - 1][i] = i;

    for (int ln = 2; ln < N + 1; ++ln) {
      for (int st = 0; st < N - ln + 1; ++st) {
        int en = st + ln;
        dp[st][en] = MX;

        for (int k = KN[st][en - 1]; k <= KN[st + 1][en]; ++k) {
          long long mn = dp[st][k] + dp[k][en] + rangePenalty[st][en - 1];
          if (mn < dp[st][en]) {
            dp[st][en] = mn;
            KN[st][en] = k;
          }
        }
      }
    }

    cout << dp[0][N] << '\n';
  }
}