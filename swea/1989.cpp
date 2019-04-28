#include <iostream>
#include <string>
using namespace std;

int main()
{
  string s;
  int T,tc;
  for(scanf("%d",&T),tc=1; tc<=T; ++tc) {
    cin >> s;
    int len = s.size(), ans = 1;

    for(int i=0; i<len/2; ++i)
      if(s[i] != s[len-i-1]) {
        ans = 0;
        break;
      }

    printf("#%d %d\n",tc,ans);
  }
}
