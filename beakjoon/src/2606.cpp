#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int comCnt, nodeCnt;
    int a, b;

    cin >> comCnt;
    cin >> nodeCnt;

    vector<int> adj[comCnt+1];

    while(nodeCnt--) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> isChecked(comCnt+1, false);
    stack<int> stk;
    stk.push(1);
    isChecked[1] = true;

    while(!stk.empty()) {
        int cur = stk.top();
        stk.pop();

        for(int nxt : adj[cur]) {
            if(isChecked[nxt]) continue;
            stk.push(nxt);
            isChecked[nxt] = true;
        }
    }

    int ans = 0;
    for(int i=1; i<=comCnt; ++i)
        if(isChecked[i]) ++ans;

    cout << ans-1 << '\n'; 
}