#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int N;
    long long num, num10;
    vector<long long> decNums;
    queue<long long> qu;

    for(int i=1; i<10; ++i) qu.push(i);
    decNums.push_back(0);

    while(!qu.empty()) {
        num = qu.front(); qu.pop();
        decNums.push_back(num);
        num10 = num*10;

        for(long long i=(num%10)-1; i>=0; --i) {
            qu.push(num10+i);
        }
    }
    sort(decNums.begin(), decNums.end());

    scanf("%d",&N);
    if(N>=decNums.size()) printf("-1\n");
    else printf("%lld\n",decNums[N]);
}
