#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

vector<int> preOrder, inOrder;

void printPostOrder(int lf, int rt, int st)
{
    if(lf >= rt) return;

    int root = preOrder[st];
    int rootIdx = lf;
    while(rootIdx < rt && inOrder[rootIdx]!= root) ++rootIdx;

    if(lf<rootIdx) printPostOrder(lf, rootIdx, st+1);
    if(rootIdx+1<rt) printPostOrder(rootIdx+1, rt, st+rootIdx-lf+1);

    cout << root << " ";
}
./
int main()
{
    int T, N, tmp;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while(T--) {
        cin >> N;
        preOrder = vector<int>(N+1);
        inOrder = vector<int>(N+1);
        for(int i=0; i<N; ++i) {
            cin >> tmp;
            preOrder[i] = tmp;
        }
        
        for(int i=0; i<N; ++i) {
            cin >> tmp;
            inOrder[i] = tmp;
        }
        printPostOrder(0, N, 0);
        cout << "\n";
    }
}