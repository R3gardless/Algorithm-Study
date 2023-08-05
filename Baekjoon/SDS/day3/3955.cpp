// 3955번 = 캔디 분배

#include <iostream>
#include <vector>

using namespace std;

int T, K, C;

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    //  X : 인당 나눠줄 사탕의 수
    //  Y : 사탕 봉지의 수
    // A * x + 1 = B * y
    // Ax + By = C 의 형태로 변환.

    cin >> T;

    while(T--) {

        cin >> K >> C;
    }

    // -Ax + By = 1
    //  A(-x) + By = 1 음수 처리, x범위가 반대가 됨
    // D = gcd(A, B)
    //  베주의 항등식 : Ax + by = C 일 때 C % D == 0 이어야만 해를 자길 수 있다.

    // s, t, r

    //  x0 = s * C / D
    //  y0 = t * C / D

    //  x = x0 + B / D * k
    //  y = y0 - A / D * k

    // x < 0
    // x0 + B * k < 0
    // k < - x0 / B

    //  0 < y <= 1e9
}