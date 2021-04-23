#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, N;
    int nums[10005];

    cin >> T;
    while(T--) {    
        cin >> N;
        for(int i=0; i<N; ++i) {
            cin >> nums[i];
        }
        sort(nums, nums+N);

        
        int lf = 1;
        int rt = 2;
        int maxDst = nums[rt]-nums[0];

        while(true) {
            if(lf+2 >= N) break;
            if(maxDst < nums[lf+2]-nums[lf]) maxDst = nums[lf+2]-nums[lf];
            lf += 2;
            if(rt+2 >= N) break;
            if(maxDst < nums[rt+2]-nums[rt]) maxDst = nums[rt+2]-nums[rt];
            rt += 2;
        }
        if(maxDst < abs(nums[rt]-nums[lf])) maxDst = abs(nums[rt]-nums[lf]);
        cout << maxDst << "\n";
    }
}