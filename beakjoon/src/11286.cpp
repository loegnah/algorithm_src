#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

class cmp {
public:
    bool operator () (const int &a, const int &b) {
        int aa = abs(a), bb = abs(b);
        if(aa != bb) return aa > bb;
        else return a > b;
    }
};

int main()
{
    int N, x;
    priority_queue<int, vector<int>, cmp> pq;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    while(N--) {
        cin >> x;
        if(x == 0) {
            if(pq.empty()) cout << "0\n";
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else pq.push(x);
    }
}