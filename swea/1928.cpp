#include <iostream>
#include <string>
using namespace std;

const int swift[3] = {8,16,24};
const int d_swift[4] = {18,12,6,0};
const unsigned int MOD = 1<<8;
string s;

unsigned int decode(char ch)
{
  unsigned int code;
  if(ch == '+') code = 62;
  else if(ch == '/') code = 63;
  else if(ch <= '9') code = 52+(ch-'0');
  else if(ch <= 'Z') code = ch-'A';
  else code = 26+(ch-'a');
  return code;
}

string intSplit(unsigned int p)
{
  string ret = "AAA";
  for(int i=2; i>=0; --i) {
    ret[i] = (char)p%MOD;
    p /= MOD;
  }
  return ret;
}

int main()
{
  int t;
  cin >> t;
  for(int tc=1; tc<=t; ++tc) {
    cin >> s;

    string ans;
    for(int i=0; i<s.size(); i+=4) {
      unsigned int p = 0;
      for(int j=0; j<4; ++j) {
        unsigned int k = decode(s[i+j]);
        p += (k << d_swift[j]);
      }
      ans += intSplit(p);
    }
    cout << "#" << tc << " " << ans << "\n";
  }
}
