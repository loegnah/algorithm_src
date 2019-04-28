#include <iostream>
#include <string>
using namespace std;

int main()
{
  string s;
  int t,tc=1,ans=0;
  for(scanf("%d",&t); tc<=t; ++tc) {
    cin >> s;
    for(int i=1; i<=10; ++i) {
      bool ck = true;
      for(int k=1; (k<=30/i) && ck; ++k) {
        for(int j=0; j<i && i*k+j<30; ++j) {
          if(s[j] != s[i*k+j]) {
            ck = false;
            break;
          }
        }
      }
      if(ck) {
        ans = i;
        break;
      }
    }
    printf("#%d %d\n",tc,ans);
  }
}
