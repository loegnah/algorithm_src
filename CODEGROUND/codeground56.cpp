#include <iostream>
using namespace std;

string ans;
int t,k;
char ch[2] = {'4','7'};

void change(int n)
{
  if(n==1) return;
  change(n/2);
  ans.push_back(ch[n%2]);
}

int main()
{
  cin >> t;
  for(int tc=1; tc<=t; ++tc) {
    cin >> k;
    ans = "";
    change(k+1);
    cout << "Case #" << tc << endl;
    cout << ans << endl;
  }
}
