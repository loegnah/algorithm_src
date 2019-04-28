#include <iostream>
using namespace std;

char ch[11];
int len[11];

int main()
{
  int t,n;
  char tmp;
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    scanf("%d",&n);
    for(int i=0; i<n; ++i) {
      cin >> tmp >> len[i];
      ch[i] = tmp;
    }

    int idx = 0, count = 0, w = 0;
    printf("#%d\n",tc);
    while(1) {
      if(count==len[idx]) {
        if(idx == n-1) break;
        idx++;
        count = 0;
      }
      if(w==10) {
        printf("\n");
        w = 0;
      }
      printf("%c",ch[idx]);
      ++count;
      ++w;
    }
    printf("\n");
  }
}
