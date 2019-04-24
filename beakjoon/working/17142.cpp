#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
#include <queue>
using namespace std;

const int CY[4] = {1,0,-1,0};
const int CX[4] = {0,1,0,-1};
const int MX= 987654321;

int N,M,virusNumber;
int board[52][52], distFromVirus[52][52][10];
bool isVisited[52][52];

bool bfs(int _y, int _x)
{
	int d,y,ny,x,nx,ret;
	bool meetVirus = false;

	queue<pair<int,int>> q;
	memset(isVisited,0,sizeof(isVisited));
	for(int i=0; i<N; ++i) distFromVirus[_y][_x][i] = MX;
	
	q.push(pair<int,int>(0,(_y<<6)+_x));
	isVisited[_y][_x] = true;

	while(!q.empty()) {
		d = q.front().first;
		x = q.front().second%64;
		y = (q.front().second)>>6;
		q.pop();

		if(board[y][x] >= 2) {
			distFromVirus[_y][_x][board[y][x]-2] = d;
			meetVirus = true;
		}

		for(int i=0; i<4; ++i) {
			ny = y+CY[i];
			nx = x+CX[i];
			if(ny>=0 && ny<N && nx>=0 && nx<N && !isVisited[ny][nx] && board[ny][nx]!=1) {
				q.push(pair<int,int>(d+1,(ny<<6)+nx));
				isVisited[ny][nx] = true;
			}
		}
	}
	return meetVirus;
}

int calcMaxDist(vector<int>& comb)
{
	int maxDist = 0;
	for(int y=0; y<N; ++y) for(int x=0; x<N; ++x) {
		int mn = MX;
		for(int i : comb) mn = min(mn,distFromVirus[y][x][i]);
		maxDist = max(maxDist,mn);
	}
	return maxDist;
}

int solve()
{
	bool isReached = true;
	for(int y=0; y<N; ++y) for(int x=0; x<N; ++x) {
		if(board[y][x] != 0) continue;
		isReached = bfs(y,x);
		if(isReached == false) break;
	}
	if(!isReached) return -1;

	vector<int> ind(virusNumber,0);
	for(int i=virusNumber-M; i<virusNumber; ++i) ind[i] = 1;
	vector<int> combList(virusNumber);
	for(int i=0; i<virusNumber; ++i) combList[i] = i;
	vector<int> comb;
	int ret = MX;

	do {
		comb.clear();
		for(int i=0; i<virusNumber; ++i)
			if(ind[i]) comb.push_back(combList[i]);
		ret = min(ret,calcMaxDist(comb));

	} while(next_permutation(ind.begin(),ind.end()));

	return ret == MX ? -1 : ret;
}
int main()
{
	scanf("%d %d",&N,&M);
	
	int tmp;
	virusNumber=0;
	for(int y=0; y<N; ++y) for(int x=0; x<N; ++x) {
		scanf("%d",&tmp);
		if(tmp==2) {
			board[y][x] = virusNumber+2;
			virusNumber++;
		}
		else board[y][x] = tmp;
	}
	printf("%d\n",solve());
}
