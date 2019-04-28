#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

vector<pair<int,int> > v;
int n, lis[100005];

int main()
{
  int t,a,b;
  setbuf(stdout,NULL);
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    scanf("%d",&n);
    v.clear();
    for(int i=0; i<n; ++i) {
      scanf("%d %d",&a,&b);
      // 최소값은 클수록 최대값은 작을 수록 범위가 작기 때문에 a는 -를 붙여 정렬한다.
      v.push_back(make_pair(-a,b));
    }
    sort(v.begin(),v.end());

    // a를 기준으로 정렬 된 v의 b를 이용하여 최장 증가 수열의 길이를 구한다.
    int maxLen = 0;
    lis[0] = -987654321;
    for(int i=0; i<n; ++i) {
      int num = v[i].second;
      if(lis[maxLen]<=num) {
        maxLen++;
        lis[maxLen] = num;
        continue;
      }
      for(int j=maxLen; j>=0; --j) {
        if(lis[j]<num) {
          lis[j+1] = num;
          break;
        }
      }
    }
    printf("Case #%d\n%d\n",tc,maxLen);
  }
}
