#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

const vector<string> COMM = {"push", "pop", "size", "empty", "front", "back"};

int commToInt(const string& comm) {
    for(int i=0; i<COMM.size(); ++i)
        if(comm == COMM[i]) return i; 
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    queue<int> qu;
    string comm;
    int num;

    while(N--) {
        cin >> comm;
        switch(commToInt(comm)) {
        case 0:
            cin >> num;
            qu.push(num);
            break;
        case 1:
            if(qu.empty()) cout << -1 << '\n';
            else {
                cout << qu.front() << '\n';
                qu.pop();
            }
            break;
        case 2:
            cout << qu.size() << "\n";
            break;
        case 3:
            cout << qu.empty() << "\n";
            break;
        case 4:
            if(qu.empty()) cout << -1 << '\n';
            else cout << qu.front() << '\n';
            break;
        case 5:
            if(qu.empty()) cout << -1 << '\n';
            else cout << qu.back() << '\n';
            break;
        }
    }
}