// 백준 15551번 = if 3

#include <iostream>
#include <string>

using namespace std;

int N;

// Java hashCode 공식 + ASCII 코드표 참고해서 풀기!
// hashcode = s[0] * 31^(n-1) + s[1] * 31^(n-2) + ... + s[n-2] + s[n-1]


int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N / 2; ++i) {
        cout << "Aa";
    }

    if(N % 2 == 1) cout << "A\n";
    else cout << "\n";

    for(int i = 0; i < N / 2; ++i) {
        cout << "BB";
    }

    if(N % 2 == 1) cout << "A\n";
    else cout << "\n";

    return 0;   
}