#include <cstdio>
#include <list>
#include <utility>
using namespace std;

const int CX[8] = {-1,0,1,1,1,0,-1,-1};
const int CY[8] = {1,1,1,0,-1,-1,-1,0};

int N,M,K;
int A[12][12], eng[12][12];
int new_tree_cnt[12][12];
list<pair<int,int> > trees[12][12];

void input_init()
{
    int x,y,z;

    scanf("%d %d %d",&N, &M, &K);

    for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) {
        scanf("%d",&A[i][j]);
        eng[i][j] = 5;
    }

    for(int i=0; i<M; ++i) {
        scanf("%d %d %d",&x, &y, &z);
        trees[x-1][y-1].push_back(make_pair(z,1));
    }
}

void make_new_trees(int x, int y, int tree_cnt) 
{
    int nx = 0, ny = 0;

    for(int i=0; i<8; ++i) {
        nx = x+CX[i];
        ny = y+CY[i];
        if(nx<0 || nx>=N || ny<0 || ny>=N) continue;
        new_tree_cnt[nx][ny] += tree_cnt;
    }
}

void spring_and_summer()
{
    int idx = 0, rmn = 0;
    bool end_flag = false;

    for(int x=0; x<N; ++x) for(int y=0; y<N; ++y) new_tree_cnt[x][y] = 0;

    for(int x=0; x<N; ++x) for(int y=0; y<N; ++y) {
        rmn = -1;
        idx = 0;
        end_flag = false;

        auto iter = trees[x][y].begin();

        for( ; iter != trees[x][y].end(); iter++) {
            int& age = (*iter).first;
            int& cnt = (*iter).second;
            
            if(eng[x][y] < age*cnt) {
                rmn = cnt - eng[x][y]/age;
                cnt = eng[x][y]/age;
                end_flag = true;
            }

            eng[x][y] -= age*cnt;
            age++;
            if(age%5 == 0) make_new_trees(x,y,cnt);

            if(end_flag) break;

            idx++;
        }

        if(rmn == -1) continue;
        
        //summer
        eng[x][y] += (((*iter).first-1)/2) * rmn;
        auto siter = iter;
        if((*siter).second != 0) siter++;
        for(iter++; iter != trees[x][y].end(); iter++) {
            eng[x][y] += ((*iter).first/2) * (*iter).second;
        }
        trees[x][y].erase(siter,trees[x][y].end());
    }
}

void fall_and_winter()
{
    for(int x=0; x<N; ++x) for(int y=0; y<N; ++y) {
        //winter
        eng[x][y] += A[x][y];

        //fall 
        if(new_tree_cnt[x][y] == 0) continue;
        trees[x][y].push_front(make_pair(1,new_tree_cnt[x][y]));
        
    }
}

int calc_total_trees()
{
    int ret = 0;
    for(int x=0; x<N; ++x) for(int y=0; y<N; ++y) {
        for(pair<int,int> tree_info : trees[x][y]) {
            ret += tree_info.second;
        }
    }
    return ret;
}

void solve()
{
    for(int tm=0; tm<K; ++tm) {
        spring_and_summer();
        fall_and_winter();
    }
}

int main()
{
    input_init();
    solve();
    printf("%d\n",calc_total_trees());
}