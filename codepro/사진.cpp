#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
struct st{
	int X, ID;
};
st A[50010];
int totCnt = 0, counts[50010];

bool cmp (const st& a, const st& b) { return a.X < b.X; }
bool cmp2 (const st& a, const st& b) {return a.ID < b.ID; }

void InputData(){
	scanf("%d",&N);
	for (int i = 0; i < N; i++) scanf("%d %d",&A[i].X,&A[i].ID);
}

void indexing()
{
	sort(A,A+N,cmp2);
	
	int idx = 0;

	for(int i=0; i<N-1; ++i) A[i].ID = (A[i].ID==A[i+1].ID) ? idx : idx++; 
	
	A[N-1].ID = idx;

	totCnt = idx+1;
}

int solve()
{
	sort(A,A+N,cmp);

    int st = 0, en = A[N-1].X-A[0].X;
    const int A0X = A[0].X;
	int cic = 0;
    while(st<en) {
        int len = (en+st)/2;
        bool isOk = false;
        int cnt = 0, left = 0, right = N-1;

        memset(counts,0,sizeof(int)*totCnt);

        for(int i=0; i<N; ++i) {
            if(A[i].X - A0X > len) {
                right = i-1;
                break;
            }
            if(counts[A[i].ID]==0) cnt++;
            counts[A[i].ID]++;
        }

        if(cnt==totCnt) isOk=true;
        else {
            while(right < N-1) {
                right++;
                if(counts[A[right].ID]==0) cnt++;
                counts[A[right].ID]++;

                while(A[right].X-A[left].X > len) {
                    counts[A[left].ID]--;
                    if(counts[A[left].ID]==0) cnt--;
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
	return en;
}

int main(){

	InputData();

	indexing();

	printf("%d\n",solve());
    
}
