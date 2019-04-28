#include <iostream>
#include <string>
using namespace std;

const string CODE[10] = {
  "0001101","0011001","0010011","0111101","0100011",
  "0110001","0101111","0111011","0110111","0001011"
};
const int CODE_LEN = 7;
const int CODE_TOT_LEN = 56;

string ipt[55];
int ans[8];

bool isCodeStart(string& p)
{
  for(int i=0; i<10; ++i)
    if(CODE[i]==p) return true;
  return false;
}

int codeToInt(string& p)
{
  for(int i=0; i<10; ++i) {
    if(p==CODE[i]) return i;
  }
  return -1;
}

bool bitCheck()
{
  return ((ans[0]+ans[2]+ans[4]+ans[6])*3
          +(ans[1]+ans[3]+ans[5])+ans[7])%10==0;
}

bool isTotalCode(int h,int w)
{
  int num;

  for(int i=0; i<8; i++) {
    string p = ipt[h].substr(w+i*7,CODE_LEN);
    num = codeToInt(p);
    if(num != -1) ans[i] = num;
    else return false;
  }
  return bitCheck();
}

bool blockCheck(int h,int w)
{
  for(int x=w; x<w+56; ++x) {
    char a = ipt[h][x];
    for(int y=h+1; y<h+5; ++y) {
      if(a != ipt[y][x]) return false;
    }
  }
  return true;
}

int main()
{
  int t,n,m;

  cin >> t;
  for(int tc=1; tc<=t; ++tc) {
    cin >> n >> m;
    for(int i=0; i<n; ++i) cin >> ipt[i];

    int h = 0, w = 0, sumAns = 0;

    while(h<n-5) {
      if(blockCheck(h,w)) {
        string tmp = ipt[h].substr(w,CODE_LEN);
        if(isCodeStart(tmp)!=-1) {
          if(isTotalCode(h,w)) {
            for(int i=0; i<8; ++i) sumAns += ans[i];
            break;
          }
        }
      }
      if(w<m-CODE_TOT_LEN) w++;
      else {h++; w=0;}
    }
    cout << "#" << tc << " " << sumAns << "\n";
  }
}
