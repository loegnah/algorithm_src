#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n,m;
string ipt;
int arr[1001][1001];
int h[1001][1001];

int main()
{
  cin >> n >> m;
  for(int i=0; i<n; ++i) {
    cin >> ipt;
    for(int j=0; j<m; ++j)
      arr[i][j] = ipt[j] - '0';
  }
  int sum = 0, ans = 0;
  for(int j=0; j<m; ++j) {
    if(arr[0][j]) {
      h[0][j] = 1;
      ans = 1;
    }
    else
      h[0][j] = 0;
  }

  for(int i=1; i<n; ++i) {
    sum = 0;
    for(int j=0; j<m; ++j) {
      if(arr[i][j]) {
        h[i][j] = min(h[i-1][j],min(h[i][j-1],h[i-1][j-1]))+1;
      }
      else {
        sum = 0;
        h[i][j] = 0;
      }
      ans = max(ans,h[i][j]);
    }
  }
  printf("%d",ans*ans);
}
