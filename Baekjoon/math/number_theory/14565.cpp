// 14565번 = 역원 구하기 (unsolved)

#include <iostream>

using namespace std;

typedef long long ll;

ll N, A, b, c;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> A;

    // 덧셈 역원 구하기
    b = N > A ? N - A : (N - A) + N;
    
    // 곱셈 역원 구하기 (EEA 사용)


    return 0;

}