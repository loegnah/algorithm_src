#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<int> num;
string s;

int main()
{
    int n,tmp;
    for(int tc=1; tc<=10; ++tc) {
        cin >> n;
        cin >> s;

        num = stack<int>();
        num.push(s[0]-'0');

        for(int i=2; i<n; i+=2) {
            if(s[i-1] == '+')
                num.push(s[i]-'0');
            else {
                tmp = num.top()*(s[i]-'0');
                num.pop();
                num.push(tmp);
            }
        }

        int ans = 0;
        while(!num.empty()) {
            ans += num.top();
            num.pop();
        }

        printf("#%d %d\n",tc,ans);
    }
}
