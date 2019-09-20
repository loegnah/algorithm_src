#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MX_LOC = 99999;

class Tree {
public:
    int N;
    vector<int> pr;
    vector<int> lc, rc;
    vector<int> minLf, maxRt;
    int totLevel;

    Tree(): N(0) {}
    Tree(int _N): N(_N+1), totLevel(0) {
        pr = vector<int>(N,-1);
        lc = vector<int>(N,-1);
        rc = vector<int>(N,-1);
        minLf = vector<int>(N,MX_LOC);
        maxRt = vector<int>(N,-1);
    }

    void setChild(int p, int l, int r) {
        if(l != -1) pr[l] = p;
        if(r != -1) pr[r] = p;
        lc[p] = l;
        rc[p] = r;
    }

    int checkLoc(int node, int baseLoc, int level) {
        int chCnt = 0;
        if(lc[node] != -1) chCnt += checkLoc(lc[node], baseLoc, level+1);

        int myLoc = baseLoc + chCnt + 1;
        if(rc[node] != -1) chCnt += checkLoc(rc[node], myLoc, level+1);


        minLf[level] = min(myLoc, minLf[level]);
        maxRt[level] = max(myLoc, maxRt[level]);
        totLevel = max(level, totLevel);

        return 1+chCnt;
    }

    void solve() {
        int root = 0;
        for(int i=1; i<=N; ++i) {
            if(pr[i] == -1) {
                root = i;
                break;
            }
        }

        checkLoc(root, 0, 1);
        
        int ansLevel = 1, mxWidth = -1;
        for(int i=1; i<=totLevel; ++i) {
            if(mxWidth < maxRt[i]-minLf[i]) {
                mxWidth = maxRt[i]-minLf[i];
                ansLevel = i;
            }
        }
        cout << ansLevel << ' ' << mxWidth+1 << '\n';
    }
};


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, p, l, r;
    cin >> n;

    Tree *tree = new Tree(n);

    for(int i=1; i<=n; ++i) {
        cin >> p >> l >> r;
        tree->setChild(p,l,r);
    }

    tree->solve();
}