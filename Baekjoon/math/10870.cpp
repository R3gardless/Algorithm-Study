// 백준 10870번 = 피보나치 수 5

#include <iostream>

using namespace std;

int N;

int fibo(int N) {
    if(N == 0) return 0;
    else if(N == 1) return 1;
    else if(N == 2) return 1;
    else return fibo(N - 1) + fibo(N - 2);
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    cout << fibo(N) << '\n';

    return 0;
}