#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

int T,D,W,K,minInsert;
int film[13][20];

int main()
{
  int allcase,inst_cnt,idx,d,w,cng,pre,same,tmp_cs,cur;
  bool pass;

  scanf("%d",&T);
  for(int TC=1; TC<=T; ++TC)
  {
    scanf("%d %d %d",&D,&W,&K);
    for(d=0; d<D; ++d) for(w=0; w<W; ++w)
      scanf("%d",&film[d][w]);

    minInsert = 99;
    allcase = pow(3,D);

    for(int cs=0; cs<allcase; ++cs) {
      inst_cnt = 0;
      idx = 0;
      pass = true;
      tmp_cs = cs;

      int insertLine[13] = {0,};

      for(int i=0; tmp_cs; ++i) {
        int cng = tmp_cs%3;
        if(cng) {
          insertLine[i] = cng;
          inst_cnt++;
        }
        tmp_cs /= 3;
      }
      if(minInsert<=inst_cnt) continue;

      for(w=0; w<W; ++w)
      {
        pre = -1;
        same = 0;
        for(d=0; d<D; ++d)
        {
          cur = (insertLine[d] ? insertLine[d]-1:film[d][w]);
          if(pre==cur) same++;
          else { pre = cur; same=1; }

          if(same==K) break;
        }
        if(same!=K) { pass=false; break;}
      }
      if(pass) minInsert = inst_cnt;
    }
    printf("#%d %d\n",TC,minInsert);
  }
}
