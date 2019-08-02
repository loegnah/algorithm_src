#include <cstdio>
#include <cstring>
using namespace std;

int n, maxBuyDay, ansDayLong, ansStartDay, ansEndDay;
long long initMoney, buyCost, minPrf, sellCost;
long long partPrf[100005];
bool isMinus[100005];

void solve()
{
    int startDay = 1;
    int endDay = 1;
    int dayLong = 1;

    while(true) {
        while(endDay < n && (isMinus[endDay] || (partPrf[endDay] - partPrf[startDay-1] < minPrf)))
            ++endDay;
    
        while(startDay < endDay && (isMinus[startDay] || (partPrf[endDay] - partPrf[startDay+1] >= minPrf)))
            ++startDay;

        dayLong = endDay-startDay+1;
        if(partPrf[endDay] - partPrf[startDay-1] >= minPrf && dayLong <= maxBuyDay && ansDayLong >= dayLong) {
            ansDayLong = endDay-startDay+1;
            ansStartDay = startDay;
            ansEndDay = endDay;
        }

        endDay++;
        if(endDay >= n) break;
    }
}

void input_init()
{
    scanf("%d %lld %lld %lld",&n, &initMoney, &buyCost, &minPrf);
    
    maxBuyDay = buyCost ? initMoney/buyCost : n;
    if(maxBuyDay > n) maxBuyDay = n;

    ansDayLong = n+1;
    ansStartDay = ansEndDay = -1;

    memset(isMinus, 0, sizeof(isMinus));
    partPrf[0] = 0;
    for(int i=1; i<=n; ++i) {
        scanf("%lld",&sellCost);
        partPrf[i] = partPrf[i-1] + sellCost - buyCost;
        if(sellCost - buyCost <= 0) isMinus[i] = true;
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--) {
        input_init();
        solve();

        if(ansStartDay == -1) printf("-1\n");
        else printf("%d %d\n",ansStartDay, ansEndDay);
    }
}