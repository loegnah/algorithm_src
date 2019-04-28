#include <cstdio>
#include <cstring>
using namespace std;

char NUM[15][5] = {"ZRO", "ONE", "TWO", "THR", "FOR",
                      "FIV", "SIX", "SVN", "EGT", "NIN"};
int count[10];
char ipt[5];

int main()
{
  int t,n;
  char tmp[10];
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    scanf("%s%d",tmp,&n);

    for(int i=0; i<10; ++i) count[i] = 0;

    for(int i=0; i<n; ++i) {
      scanf("%s",ipt);
      for(int j=0; j<10; ++j) {
        if(strcmp(ipt,NUM[j])==0) {count[j]++; break;}
      }
    }

    printf("#%d\n",tc);
    for(int i=0; i<10; ++i) {
      for(int j=0; j<count[i]; ++j) printf("%s ",NUM[i]);
    }
    printf("\n");
  }
}
