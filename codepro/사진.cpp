#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

int N;//제품 수
struct st{
	int X, ID;//위치, 아이디
};
st A[50010];
int IDs[50010], totCnt;
map<int,int> mp;

bool cmp (const st& a, const st& b) { return a.X<b.X; }

void InputData(){
    totCnt = 0;
	scanf("%d",&N);
	for (int i = 0; i < N; i++){
		scanf("%d %d",&A[i].X,&A[i].ID);
        if(mp[A[i].ID]==0) {
            totCnt++;
            mp[A[i].ID]++;
        } 
	}
}

int main(){
	int ans = -1;

	InputData();			//	입력 함수

	//	코드를 작성하세요
    sort(A,A+N,cmp);

    int st = 0, en = A[N-1].X-A[0].X;
    const int A0X = A[0].X;

    while(st<en) {
        int len = (en+st)/2;
        bool isOk = false;
        int cnt = 0, left = 0, right = N-1;
        mp.clear();

        for(int i=0; i<N; ++i) {
            if(A[i].X - A0X > len) {
                right = i-1;
                break;
            }
            if(mp[A[i].ID]==0) cnt++;
            mp[A[i].ID]++;
        }

        if(cnt==totCnt) isOk=true;
        else {
            while(right < N-1) {
                right++;
                if(mp[A[right].ID]==0) cnt++;
                mp[A[right].ID]++;

                while(A[right].X-A[left].X > len) {
                    mp[A[left].ID]--;
                    if(mp[A[left].ID]==0) cnt--;
                    left++;
                }

                if(cnt==totCnt) {
                    isOk=true;
                    break;
                }
            }
        }
        if(isOk) en = len;
        else st = len+1;
    }

	printf("%d\n",en);	//	정답 출력
	return 0;
}
