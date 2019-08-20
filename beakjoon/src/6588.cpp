#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MX = 1000000;

bool isPrime[MX+5];
vector<int> primes;

void find_primes() 
{
    memset(isPrime, -1, sizeof(isPrime));

    isPrime[0] = isPrime[1] = false;

    for(int i=3; i<MX; i+=2) {
        if(isPrime[i]) {
            primes.push_back(i);

            int ii = i+i;
            while(ii < MX) {
                isPrime[ii] = false;
                ii += i;
            }
        }
    }

}

void solve(int num)
{
    for(int a : primes) {
        if(isPrime[num-a]) {
            cout << num << " = " << a << " + " << num-a << '\n';
            break;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    find_primes();

    int num;
    while(true) {
        cin >> num;
        if(num == 0) break;

        solve(num);
    }
}