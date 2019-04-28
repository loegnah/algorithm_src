#include <iostream>
#include <string>
using namespace std;

string s;

int main()
{
    int n;
    for(int tc=1; tc<=10; ++tc) {
        int ans = 0;
        cin >> n;
        cin >> s;
        for(int i=0; i<n; i+=2) ans += s[i];
        ans -= '0'*((n+1)/2);
        printf("#%d %d\n",tc,ans);
    }
}
