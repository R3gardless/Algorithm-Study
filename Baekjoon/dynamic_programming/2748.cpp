// 2748번 = 피보나치 수 2

#include <iostream>

using namespace std;
typedef long long ll;

ll fibo[100];
int N;
int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    fibo[1] = 1;

    cin >> N;

    for(int i = 2; i <= N; ++i) fibo[i] = fibo[i-1] + fibo[i-2];

    cout << fibo[N] << '\n';

    return 0;
}