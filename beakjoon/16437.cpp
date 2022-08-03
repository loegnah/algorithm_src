#include <iostream>
#include <vector>
using namespace std;

class Tree {
public:
    int N;
    vector<int> life;
    vector<vector<int>> children;

    Tree(): N(0) {}
    Tree(int _N): N(_N) {
        life = vector<int>(N+1, 0);
        children.resize(N+1);
    }
    
    void setChild(int p, int c) {
        children[p].push_back(c);
    }

    long long survival(int cur) {
        int cur_life = life[cur];
        
        for(int child : children[cur]) {
            cur_life += survival(child);
        }

        if(cur_life < 0) cur_life = 0;
        return cur_life;
    }
};

int main()
{
    int n, t, a, p;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    Tree *tree = new Tree(n);

    for(int i=2; i<=n; ++i) {
        cin >> t >> a >> p;
        tree->setChild(p,i);
        if(t == 'w') tree->life[i] = -a;
        else tree->life[i] = a;
    }

    tree->survival(1);
}