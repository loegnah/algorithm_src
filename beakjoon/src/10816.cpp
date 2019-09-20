#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, cardNum, findNum;
    unordered_map<int,int> cardNumCnt;
    vector<int> cnts;

    cin >> N;
    for(int i=0; i<N; ++i) {
        cin >> cardNum;
        cardNumCnt[cardNum]++;
    }
    cin >> M;
    while(M--) {
        cin >> findNum;
        cnts.push_back(cardNumCnt[findNum]);
    }

    for(int cnt : cnts) cout << cnt << ' ';
    cout << '\n';
}