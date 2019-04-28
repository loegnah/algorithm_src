#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
using namespace std;

enum {DONT_GO=-2, BLOCKED, NORMAL=1, MUST_GO};

const string IMPOSSIBLE = "IMPOSSIBLE";

deque<int> CY = {1,0,-1,0};
deque<int> CX = {0,-1,0,1};
deque<char> CMD = {'D','L','U','R'};

int R,C,r,c;
int board[105][105];

void checkState(const int y, const int x, vector<int>& states)
{
    for(int dr=0; dr<4; ++dr) {
        int ny = y+CY[dr], nx = x+CX[dr];
        int& statesDr = states[dr];

        statesDr = NORMAL;
        
        if(board[ny][nx]) {
            statesDr = BLOCKED;
            continue;
        }

        int nearBlockCnt = 0;
        for(int ndr=0; ndr<4; ++ndr) {
            if(board[ny+CY[ndr]][nx+CX[ndr]])
                nearBlockCnt++;
        }
        
        if(nearBlockCnt>=3) statesDr = MUST_GO;
    }
}

bool impossibleCheck()
{
    if(R%2 && C%2 && (r%2!=c%2)) return true;
    if(R==1 && c!=1 && c!=C) return true;
    if(C==1 && r!=1 && r!=R) return true;
    return false;
}

void drcPriorityChange()
{
    CY.push_front(CY.back()); CY.pop_back();
    CX.push_front(CX.back()); CX.pop_back();
    CMD.push_front(CMD.back()); CMD.pop_back();
}

void solve()
{
    // 이런 경우아니면 무조건 답 나옴
    if(impossibleCheck()) {
        cout << IMPOSSIBLE << endl;
        return;
    }

    // reset
    memset(board,0,sizeof(board));  // no block = 0
    for(int y=0; y<=R+1; ++y) board[y][0] = board[y][C+1] = 1; // block = 1
    for(int x=0; x<=C+1; ++x) board[0][x] = board[R+1][x] = 1;
    
    int moveCnt = 0, maxMoveCnt = R*C-1;
    string ans = "";
    vector<int> nextStates(4);

    int y = r, x = c;

    while(moveCnt < maxMoveCnt) {
        board[y][x] = 1;
        moveCnt++;
        
        checkState(y,x,nextStates);

        int maxState = -3, nxtDr = -1;
        for(int dr=0; dr<4; ++dr) {
            if(nextStates[dr] > maxState) {
                maxState = nextStates[dr];
                nxtDr = dr;
            }
        }

        if(maxState < 0) {
            // 방향 우선순위에 따라 안되는 경우 방향 우선순위 바꿔서 다시 품
            drcPriorityChange();
            solve();
            return;
        }

        y += CY[nxtDr];
        x += CX[nxtDr];
        ans += CMD[nxtDr];
    }

    cout << ans << endl;
}

int main()
{
    
    int T;
    cin >> T;
    while(T--) {
        cin >> R >> C >> r >> c;
        solve();
    }
}