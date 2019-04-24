#include <iostream>
#include <string>
using namespace std;

const char EQ = '=' , MN = '-';

int main()
{
  int ans = 0;
  string s;
  cin >> s;
  for(int i=0; i<s.length(); ++i) {
    char cur = s[i], nx = s[i+1];
    switch(cur) {
      case 'c':
        if(nx==EQ || nx==MN) i++;
        break;
      case 'd':
        if(nx==MN) i++;
        else if(i<s.length()-1 && nx=='z' && s[i+2]==EQ) i+=2;
        break;
      case 'l':
        if(nx=='j') i++;
        break;
      case 'n':
        if(nx=='j') i++;
        break;
      case 's':
        if(nx==EQ) i++;
        break;
      case 'z':
        if(nx==EQ) i++;
        break;
    }
    ans++;
  }
  printf("%d",ans);
}
