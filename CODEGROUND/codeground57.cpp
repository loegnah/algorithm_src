#include <cstdio>
#include <stack>
using namespace std;

char gh[7] = "(){}[]";
char ipt[1000005];
stack<int> st;

int main(int argc, char** argv)
{
  int t;
  setbuf(stdout,NULL);
  scanf("%d",&t);
  for(int tc=1; tc<=t; ++tc) {
    scanf("%s",ipt);
    st = stack<int>();
    int k=0, mx=0, cur=0, idx;
    while(ipt[k]) {
      char ch = ipt[k];
      for(idx=0; idx<6; ++idx)
        if(ch == gh[idx])
          break;
      //열릴 때
      if(idx%2==0) {
        if(cur > 0) {
          st.push(cur*10);
          cur = 0;
        }
        st.push(idx);
      }
      //닫힐 때
      else {
        if(st.empty() || (st.top() != idx-1)) {
          st = stack<int>();
          cur = 0;
        }
        else {
          cur++;
          st.pop();
          if(!st.empty() && (st.top()/10 > 0)) {
            cur += st.top()/10;
            st.pop();
          }
          mx = (mx>cur) ? mx:cur;
        }
      }
      k++;
    }
    printf("Case #%d\n",tc);
    printf("%d\n",mx*2);
  }
}
