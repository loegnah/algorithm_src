#include <cstdio>
using namespace std;

enum {BLK,WHT};

int checkColor(int num)
{
    num--;
    if((num/8)%2==0) return num%2 ? BLK:WHT;
    else return num%2 ? WHT:BLK;
}

int main()
{
    int T, a,b;
    char a_str[3];

    scanf("%d",&T);
    while(T--) {
        scanf("%s %d",a_str,&b);
        a = (a_str[0]-'A'+1) + 8*(a_str[1]-'1');

        int a_color = checkColor(a);
        int b_color = checkColor(b); 

        if(a_color==b_color) printf("YES\n");
        else printf("NO\n");
    }
}