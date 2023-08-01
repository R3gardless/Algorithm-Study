// 13251번 = 조약돌 꺼내기

#include <iostream>

using namespace std;

int M, K;
double N, arr[51], ans;

double combination(double n, double r) {
    double x = 1.0, y = 1.0;
    if(r > n) return 0.0;

    for(double i = n; i > n - r; --i) y *= i;
    for(double i = r; i > 0; --i) x *= i;

    return y / x;
}

// 전체 경우의 수 = 전체 개수 C 4

// 같은 경우에 대한 경우의 수

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> M;

    for(int i = 0; i < M; ++i) {
        cin >> arr[i];
        N += arr[i];
    }
    cin >> K;
    if(M == 1 || K == 1) {
        cout << 1.0 << '\n';
        return 0;
    }

    for(int i = 0; i < M; ++i) {
        ans += combination(arr[i], K);
    }

    printf("%.19f", ans / combination(N, K));

    return 0;

}