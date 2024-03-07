// 백준 10872번 = 팩토리얼

#include <iostream>

using namespace std;

int N;

int factorial(int N) {
    if(N == 0) return 1;
    else return N * factorial(N - 1);
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    cout << factorial(N) << '\n';

    return 0;
}