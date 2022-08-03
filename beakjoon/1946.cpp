#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int N;
vector<pair<int,int>> v1, v2;
vector<bool> isChecked;

void input_init()
{
    int a, b;

    v1.clear();
    v2.clear();

    cin >> N;
    for(int i=0; i<N; ++i) {
        cin >> a >> b;
        v1.push_back(pair<int,int>(a,i));
        v2.push_back(pair<int,int>(b,i));
    }
    isChecked = vector<bool>(N,false);

    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
}

int solve()
{
    int v2_idx = (int)v2.size() -1;
    int cnt = 0;

    for(int i=0; i<N; ++i) {
        int person = v1[i].second;

        if(isChecked[person]) continue;
        cnt++;
        
        while(v2_idx >= 0) {
            int opt = v2[v2_idx].second;
            if(opt == person) {
                v2_idx--;
                break;
            }
            isChecked[opt] = true;
            v2_idx--;
        }
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        input_init();
        cout << solve() << '\n';
    }
}