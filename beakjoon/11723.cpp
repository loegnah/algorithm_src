#include <cstdio>
#include <cstring>
using namespace std;

const char* ADD = "add";
const char* REMOVE = "remove";
const char* CHECK = "check";
const char* TOGGLE = "toggle";
const char* ALL = "all";
const char* EMPTY = "empty";

char cmm[10];
int n,num, sets[21];

int main()
{
    for(int i=1; i<=20; ++i) sets[i] = 0;
    scanf("%d",&n);
    
    for(int ct=0; ct<n; ++ct) {
        scanf("%s",cmm);
        if(!(cmm == ALL || cmm == EMPTY)) scanf("%d",&num);
        if(!strcmp(cmm,ADD)) sets[num] = 1;
        else if(!strcmp(cmm,REMOVE)) sets[num] = 0;
        else if(!strcmp(cmm,CHECK)) sets[num] ? printf("1\n") : printf("0\n");
        else if(!strcmp(cmm,TOGGLE)) sets[num] = 1-sets[num];
        else if(!strcmp(cmm,ALL))
            for(int i=1; i<=20; ++i) sets[i] = 1;
        else
            for(int i=1; i<=20; ++i) sets[i] = 0;
    }   
}