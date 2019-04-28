#include <string>
#include <iostream>
using namespace std;

const int az = 'z'-'a'+1;
const int ck[4] = {'h'-'a','e'-'a','o'-'a','l'-'a'};


int main()
{
  int t;
  int ct[az];
  cin >> t;
  for(int tc=1; tc<=t; ++tc) {
    string s;
    cin >> s;
    for(int i=0; i<az; ++i) ct[i] = 0;
    for(int i=0; i<s.size(); ++i) ct[s[i]-'a']++;

    int ans = ct[ck[3]]/2;
    for(int i=0; i<3; ++i) ans = (ans<ct[ck[i]]) ? ans : ct[ck[i]];
    printf("Case #%d\n%d\n",tc,ans);
  }
}
