#include <string>
#include <vector>
#include <iostream>
using namespace std;

const int L = 'z'-'a'+1;

int main()
{
  int n, ans = 0;
  scanf("%d",&n);
  while(n--) {
    vector<bool> ck(L,false);
    string s;
    cin >> s;

    int pre = s[0]-'a';
    ck[pre] = true;
    bool ok = true;
    for(int i=1; i<s.length(); ++i) {
      int cur = s[i]-'a';
      if(ck[cur] && cur!=pre) {
        ok = false;
        break;
      }
      ck[cur] = true;
      pre = cur;
    }
    if(ok) ans++;
  }
  printf("%d",ans);
}
