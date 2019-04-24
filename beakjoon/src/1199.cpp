#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int N;
int adj[1001][1001];
int degree[1001];
vector<int> ans;

void dfs(int cur)
{
    for(int nxt=1; degree[cur] && nxt<=N; ++nxt) {
        if(adj[cur][nxt]) {
            --adj[cur][nxt];
            --adj[nxt][cur];
            --degree[cur];
            --degree[nxt];
            dfs(nxt);
        }
    }
    ans.push_back(cur);
}

int main()
{
    bool isImpossible = false;
    scanf("%d",&N);
    for(int y=1; y<=N; ++y) {
        degree[y] = 0;
        for(int x=1; x<=N; ++x) {
            scanf("%d",&adj[y][x]);
            degree[y] += adj[y][x];
        }
        if(degree[y]%2) isImpossible = true;
    }

    if(isImpossible) {
        printf("-1\n");
        return 0;
    }

    ans.clear();
    
    for(int start=1; start<=N; ++start) {
        if(degree[start]) {
            dfs(start);
            break;
        }
    }

    for(int i=ans.size()-1; i>=0; --i) printf("%d ", ans[i]);
    printf("\n");
}