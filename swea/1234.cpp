#include <iostream>
#include <string>
using namespace std;

int main()
{
  int n;
  string str,tmp1,tmp2;
  for(int tc=1; tc<=10; ++tc) {
    cin >> n >> str;
    while(true) {
      bool ck = true;
      for(int i=0; i<str.size()-1; ++i) {
        if(str[i]==str[i+1]) {
          tmp1 = str.substr(0,i);
          tmp2 = str.substr(i+2);
          str = tmp1+tmp2;
          ck = false;
        }
      }
      if(ck) break;
    }
    cout << "#" << tc << " " << str << "\n";
  }
}
