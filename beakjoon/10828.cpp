#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

const vector<string> COMM = {"push", "pop", "size", "empty", "top"};

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

    stack<int> stk;
    string comm;
    int num;

    while(N--) {
        cin >> comm;
        switch(commToInt(comm)) {
        case 0:
            cin >> num;
            stk.push(num);
            break;
        case 1:
            if(stk.empty()) cout << -1 << '\n';
            else {
                cout << stk.top() << '\n';
                stk.pop();
            }
            break;
        case 2:
            cout << stk.size() << "\n";
            break;
        case 3:
            cout << stk.empty() << "\n";
            break;
        case 4:
            if(stk.empty()) cout << -1 << '\n';
            else cout << stk.top() << '\n';
            break;
        }
    }
}