#include <string>
#include <iostream>
using namespace std;

string str,match;
int sLen, mLen;

int main()
{
  int t,ans,i,j;
  for(int tc=1; tc<=10; ++tc) {
    cin >> t >> match >> str;

    mLen = match.size();
    sLen = str.size();
    ans = 0;

    for(i=0; i<sLen-mLen+1; ++i) {
      for(j=0; j<mLen; ++j) {
        if(str[i+j]!=match[j]) break;
      }
      if(j==mLen) ans++;
    }

    cout << "#" << tc << " " << ans << "\n";
  }
}
