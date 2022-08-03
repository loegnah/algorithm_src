#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MX = 99999;

char s[2505];
int cache[2505][2505];

int check(int a, int b)
{
    if(a>=b) return 1;

    int& ret = cache[a][b];
    if(ret != -1) return ret;

    if(s[a] != s[b])
        return ret = 0;

    return ret = check(a+1,b-1);
}

int main()
{
    memset(cache,-1,sizeof(cache));

    scanf("%s",s+1);
    int sLen = strlen(s+1);

    int minMake[sLen] = {0};
    for(int a=1; a<=sLen; ++a) {
        minMake[a] = MX;
        for(int b=1; b<=a; ++b) {
            if(check(b,a))
                minMake[a] = min(minMake[a],minMake[b-1]+1);
        }
    }
    printf("%d\n",minMake[sLen]);
}
