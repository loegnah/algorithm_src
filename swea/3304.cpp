#include <iostream>
#include <string>
using namespace std;

string a,b;
int aLen, bLen, tb[2][1002];

int mx(int p,int q) { return p>q?p:q; }

void find_lcs()
{
  for(int i=0; i<=aLen; ++i) tb[0][i] = 0;
  tb[1][0] = 0;

  for(int bi=1; bi<=bLen; ++bi) {
    int ln = bi%2;
    for(int ai=1; ai<=aLen; ++ai) {
      if(a[ai-1]==b[bi-1]) tb[ln][ai] = 1+tb[1-ln][ai-1];
      else tb[ln][ai] = mx(tb[ln][ai-1],tb[1-ln][ai]);
    }
  }
}

int main()
{
  int t;
  cin >> t;
  for(int tc=1; tc<=t; ++tc) {
    cin >> a >> b;
    aLen = a.size();
    bLen = b.size();
    find_lcs();
    cout << "#" << tc << " " << tb[bLen%2][aLen] << "\n";
  }
}
