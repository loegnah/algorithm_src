#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    int n, m, num = 0, commonCnt = 0;
    unordered_set<int> A;
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i=0; i<n; ++i) {
        cin >> num;
        A.insert(num);
    }


    for(int i=0; i<m; ++i) {
        cin >> num;
        if(A.find(num) != A.end()) ++commonCnt;
    }
    
    cout << n+m-commonCnt*2 << '\n';

}