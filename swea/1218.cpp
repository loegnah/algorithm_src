#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<char> sk;
string s;

int main()
{
    bool cache[256];
    cache['<'] = cache['('] = cache['{'] = cache['['] = true;
    cache['>'] = cache[')'] = cache['}'] = cache[']'] = false;
    for(int tc=1; tc<=10; ++tc) {
        int n,ans=1;
        sk = stack<char>();
        cin >> n;
        cin >> s;

        for(auto i=s.begin(); i!=s.end(); i++) {
            if(cache[*i]) sk.push(*i);
            else {
                if(sk.empty() || (sk.top() != (*i)-1 && sk.top() != (*i)-2))  {ans = 0; break;}
                sk.pop();
            }
        }
        cout << "#" << tc << " " << ans << "\n";
    }
}
