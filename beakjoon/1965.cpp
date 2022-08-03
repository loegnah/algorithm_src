#include <cstdio>
#include <cstring>
#include <limits>
using namespace std;

const int mxInt = numeric_limits<int>::max();

int main()
{
  int n, box, mx = -1;
  int arr[1002] = {mxInt};

  scanf("%d",&n);
  for(int i=0; i<n; ++i) {
    scanf("%d",&box);
    bool ck = true;
    int j=mx;
    for(; j>=0 && arr[j]>=box; --j) {ck = false;}
    if(ck) {
      ++mx;
      arr[mx] = box;
    }
    else {
      arr[j+1] = box;
    }
  }
  printf("%d",mx+1);
}
