#include <iostream>
#include <string>
#include <vector>
using namespace std;

int len,commNum,x,y;
string comm;
vector<string> strList;
vector<string>::iterator iter;

void insertStr()
{
  string tmp;
  cin >> x >> y;
  for(int i=0; i<y; ++i) {
    cin >> tmp;
    iter = strList.begin() + x + i;
    strList.insert(iter,tmp);
  }
}

int main()
{
  string tmp;
  for(int tc=1; tc<=10; ++tc) {
    strList.clear();

    cin >> len;
    for(int i=0; i<len; ++i) {
      cin >> tmp;
      strList.push_back(tmp);
    }
    cin >> commNum;

    for(int i=0; i<commNum; ++i) {
      cin >> comm;
      insertStr();
    }
    cout << "#" << tc << " ";
    for(int i=0; i<10; ++i) cout << strList[i] << " ";
    cout << "\n";
  }

}
