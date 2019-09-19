#include <map>
#include <iostream>
using namespace std;

int main()
{
    map<int,int> a;
    a[10] = 10;
    if(a[11]) cout << a[10];
    else cout << "a";
}