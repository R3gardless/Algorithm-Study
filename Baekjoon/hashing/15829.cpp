// 백준 15829번 = Hashing

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#define M 1234567891
#define R 31

using namespace std;

int L;
long long int res;
char ch;
    

int getChar(char ch) {
    return (ch - 'a' + 1);
}

int main() {
    
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> L;

    long long r = 1;
    for(int i = 0; i < L; ++i) {  // (M * N) % p = ((M % p) * (N % p)) % p
        cin >> ch;
        res += (getChar(ch) * r) % M;
        r = (r * 31) % M;
    }
    cout << res % M << '\n';
}
