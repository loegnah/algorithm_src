#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

string a,b;
int arr[1003][1003];

int main()
{
  cin >> a;
  cin >> b;
  memset(arr,0,sizeof arr);
  for(int y=1; y<=b.size(); ++y) {
    char by = b[y-1];
    for(int x=1; x<=a.size(); ++x) {
      char ax = a[x-1];
      if(by == ax)
        arr[y][x] = arr[y-1][x-1] + 1;
      else
        arr[y][x] = (arr[y][x-1] > arr[y-1][x]) ? arr[y][x-1] : arr[y-1][x];
    }
  }

  cout << arr[b.size()][a.size()] << endl;

  /* 여기서 부터 LCS 리빌딩하는 과정
    근데 정확히 꼭지점 부분을 찾기 위해선 아래와같이 해야됨.
    어떤 지검의 위와 왼쪽 그리고 대각선이 각각 다른 경우가 있기 때문에 */
  vector<char> ans;
  int st_x = a.size();
  int p = arr[b.size()][a.size()];
  int q = p-1;
  for(int y=b.size(); y>=0; --y) {
    for(int x=st_x; x>0; --x) {
      if(arr[y][x]==p && arr[y][x-1]==q && arr[y-1][x]==q && arr[y-1][x-1]==q) {
        ans.push_back(a[x-1]);
        st_x = x;
        p--; q--;
        break;
      }
    }
  }
  reverse(ans.begin(),ans.end());
  for(auto i=ans.begin(); i!=ans.end(); i++)
    cout << *i;

}
