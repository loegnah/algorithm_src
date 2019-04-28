#include <iostream>
#include <string>
using namespace std;

const string SI[20] = {"yotta","zetta","exa","peta","tera","giga","mega","kilo",
            "hecto","deca","deci","centi","milli","micro","nano","pico",
            "femto","ato","zepto","yocto"};
const int EPN[20] = {24,21,18,15,12,9,6,3,2,1,-1,-2,-3,-6,-9,-12,-15,-18,-21,-24};
const char DOT = '.';
const char ZERO = '0';
const int ERR = -55555;

string num, frx, sfx, ans_num;
int T, dot_idx, num_len, st1, st2, sgn1, sgn2, frx_num, ans_ex;

void input()
{
    cin >> num >> frx;
    frx_num = ERR;
    for(int i=0; i<20; ++i)
        if(SI[i] == frx) frx_num = EPN[i];
    if(frx_num == ERR) {
        sfx = frx;
        frx_num = 0;
    }
    else cin >> sfx;
}

void find_st_sgn()
{
    num_len = num.size();
    dot_idx = num_len;
    st1 = st2 = sgn1 = sgn2 = 0;
    
    for(int i=0; i<num_len; ++i)
        if(num[i] == DOT) {
            dot_idx = i;
            break;
        }
    if(dot_idx == num_len) 
        sgn1 = num_len;
    else if(dot_idx != 1) {
        sgn1 = dot_idx;
        st2 = dot_idx + 1;
        sgn2 = num_len - st2;
    }
    else {
        st1 = -1000;
        for(int i=2; i<num_len; ++i) 
            if(num[i] != ZERO) {
                st2 = i;
                sgn2 = num_len - st2;
                break;
            }  
    }
}

void calc_output()
{
    ans_num = ""; 
    ans_ex = 0;
    
    for(int i=0; i<sgn1; ++i) ans_num += num[st1+i];
    for(int i=0; i<sgn2; ++i) ans_num += num[st2+i];

    if(st1 == 0) ans_ex = dot_idx - 1;
    else ans_ex = dot_idx - st2;
    ans_ex += frx_num;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    for(int tc=1; tc<=T; ++tc) {
        input();
        find_st_sgn();
        calc_output();

        cout << "#" << tc << " " << ans_num[0];
        if(ans_num.size() > 1) cout << "." << ans_num.substr(1);
        cout << " * 10^" << ans_ex << " " << sfx << "\n";
    }
}