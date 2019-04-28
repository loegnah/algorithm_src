#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

unordered_set<string> s;

int main()
{
  int t,n,m;
  string s1,s2;
  cin >> t;
  for(int tc=1; tc<=t; ++tc) {
    cin >> n >> m;

    int ans = 0;
    s.clear();

    for(int i=0; i<n; ++i) {
      cin >> s1;
      s.insert(s1);
    }
    for(int i=0; i<m; ++i) {
      cin >> s2;
      if(s.find(s2) != s.end()) ++ans;
    }
    printf("#%d %d\n",tc,ans);
  }
}
