#include <cstdio>
using namespace std;

const int MX_LEN = 1000;
const char ZR = '0';

char str[MX_LEN];
int prr[ZR],stc[MX_LEN],rear[MX_LEN];
int strLen,stcIdx,rrIdx;

void prc_opr(char ch)
{
    if(ch != '(') {
        while(stcIdx && prr[stc[stcIdx-1]]>=prr[ch]) {
            stcIdx--;
            if(stc[stcIdx] == '(') return;

            rrIdx--;
            if(stc[stcIdx] == '+') rear[rrIdx-1] += rear[rrIdx];
            else rear[rrIdx-1] *= rear[rrIdx];
        }
    }
    stc[stcIdx++] = ch;
}

void setting_prr()
{
    prr['('] = prr[')'] = 1;
    prr['+'] = 2;
    prr['*'] = 3;
}

int main()
{
    setting_prr();

    for(int tc=1; tc<=10; ++tc) {
        stcIdx = rrIdx = 0;

        scanf("%d",&strLen);
        scanf("%s",str);

        stc[stcIdx++] = '(';
        for(int i=0; i<strLen; ++i) {
            char ch = str[i];
            if(ch<ZR) prc_opr(ch);
            else rear[rrIdx++] = ch-ZR;
        }
        prc_opr(')');
        printf("#%d %d\n",tc,rear[0]);
    }
}
