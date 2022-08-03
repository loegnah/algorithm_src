#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const long long MX = 1e9+5; 

const char A = 'a';
const char Z = 'z';
const char X = 'X';

long long cache[205][205];
string ans;

long long calcCache(const int n, const int m)
{
    cache[1][0] = cache[1][1] = 1;

    for(int a=2; a<=n+m; ++a) cache[a][0] = 1;

    for(int a=2; a<=n+m; ++a) {
        for(int b=1; b<=a; ++b) {
            cache[a][b] = min(MX, cache[a-1][b]+cache[a-1][b-1]);
        }
    }
}

void findAns(int n, int m, long long rmn)
{
    if(n == 0) {
        if(m == 0) return;
        ans.push_back(Z);
        findAns(n, m-1, rmn);
    }
    else if(m == 0) {
        ans.push_back(A);
        findAns(n-1, m, rmn);
    }
    else if(cache[n-1+m][m] >= rmn) {
        ans.push_back(A);
        findAns(n-1, m, rmn);
    }
    else {
        ans.push_back(Z);
        findAns(n, m-1, rmn-cache[n-1+m][m]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;
    
    calcCache(N, M);
    if(cache[N+M][M] < K) cout << -1 << '\n';
    else {
        findAns(N, M, K);
        cout << ans << '\n';
    }
}