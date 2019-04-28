#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int DZ = '0'*2;
const int Z = '0';

string a,b,ans;

void swap_str()
{
  string tmp = a;
  a = b;
  b = tmp;
}

void sum_long_num()
{
  ans = "";
  int aLen = a.size(), bLen = b.size(), sum, carry = 0;
  for(int i=0; i<bLen; ++i) {
    sum = a[i]+b[i]-DZ+carry;
    carry = 0;
    if(sum >= 10) {
      sum -= 10;
      carry = 1;
    }
    ans.push_back(sum+Z);
  }
  for(int i=bLen; i<aLen; ++i) {
    sum = a[i]-Z+carry;
    carry = 0;
    if(sum >= 10) {
      sum -= 10;
      carry = 1;
    }
    ans.push_back(sum+Z);
  }
  if(carry == 1) ans.push_back('1');
}

int main()
{
  int t;
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    cin >> a >> b;
    if(a.size()<b.size()) swap_str();
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    sum_long_num();
    reverse(ans.begin(), ans.end());
    cout << "#" << tc << " " << ans << "\n";
  }
}
