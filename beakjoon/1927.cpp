#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, num;
    cin >> N;

    priority_queue<int> pq;

    while(N--) {
        cin >> num;
        
        if(num)
            pq.push(-num);
        else if(pq.empty()) 
            cout << "0" << '\n';
        else {
            cout << -pq.top() << '\n';
            pq.pop();
        }
    }
}