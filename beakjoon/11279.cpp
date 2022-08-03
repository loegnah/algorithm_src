#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int N, x;
    priority_queue<int> pq;
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    while(N--) {
        cin >> x;
        
        if(x > 0) pq.push(x);
        else {
            if(pq.empty()) cout << '0' << '\n';
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
    }
}
