#include <iostream>
#include <string>
using namespace std;

int main()
{
  const int sz = 'z'-'a'+1;
  int st[sz];
  string s;
  cin >> s;
  fill_n(st,sz,-1);
  for(int i=0; i<s.length(); ++i) {
    int idx = s[i]-'a';
    if(st[idx] == -1) st[idx] = i;
  }
  for(int& a: st) printf("%d ",a);
}
