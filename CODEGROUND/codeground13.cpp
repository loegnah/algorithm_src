#include <cstdio>
#include <cmath>
using namespace std;

int main(int argc, char** argv)
{
	int T, test_case;
  setbuf(stdout,NULL);
	scanf("%d",&T);

  int N,ans,max_b;
	for(test_case = 1; test_case <= T; test_case++)
	{
    scanf("%d",&N);
		max_b = ans = N+1;
		int sqrtN = (int)sqrt(N);
		for(int a=sqrtN; a>=1; --a)
      if((N%a==0) && (a<N/a-1)) {
				ans = max_b = N/a-1;
        break;
      }
    bool ck = true;
    for(int b=2; ck && b <= sqrtN; ++b) {
      unsigned long long sum_b = 1;
			int bn = b;
      while(sum_b<N) {
        sum_b += bn;
        bn *= b;
        if(((N%sum_b)==0) &&((N/sum_b)<b)) {
          ans = b;
          ck = false;
          break;
        }
      }
    }
    printf("Case #%d\n%d\n",test_case,ans);
	}

	return 0;
}
