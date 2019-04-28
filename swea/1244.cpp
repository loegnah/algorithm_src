#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int len,ans;
string ipt;
bool same;

void swap_str(int a, int b)
{
  char tmp = ipt[a];
  ipt[a] = ipt[b];
  ipt[b] = tmp;
}

int iptToInt()
{
  int ret = 0, k = 1;
  for(int i=len-1; i>=0; --i) {
    ret += k*(ipt[i]-'0');
    k *= 10;
  }
  return ret;
}

bool findSame()
{
  bool tmp[10] = {false,};
  for(int i=0; i<len; ++i) {
    int k = ipt[i]-'0';
    if(tmp[k]) return true;
    tmp[k] = true;
  }
  return false;
}

void solve(int cur,int count)
{
  if(count==0) {
    int tmp = iptToInt();
    if(ans<tmp) ans = tmp;
    return;
  }
  if(cur == len-1) {
    if((count%2==0) || same) {
      int tmp = iptToInt();
      if(ans<tmp) ans = tmp;
      return;
    }
    return;
  }

  solve(cur+1,count);
  for(int opr = cur+1; opr<len; ++opr) {
    swap_str(cur,opr);
    solve(cur+1,count-1);
    swap_str(cur,opr);
  }
}

int main()
{
  int t,dif,count;
  cin >> t;
  for(int tc=1; tc<=t; ++tc) {
    cin >> ipt >> count;

    same = findSame();
    len = ipt.size();
    ans = 0;
    dif = count-len+1;

    if(dif>=0) {
      sort(ipt.begin(),ipt.end());
      reverse(ipt.begin(),ipt.end());
      if(dif%2) swap_str(len-1,len-2);
      cout << "#" << tc << " " << ipt << "\n";
    }
    else {
      solve(0,count);
      cout << "#" << tc << " " << ans << "\n";
    }
  }
}
