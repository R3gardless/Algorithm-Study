// 9095번 = 1,2,3 더하기

#include <iostream>

using namespace std;

int T, N;
int dp[11];
// 1. dp 정의 - dp[i] i는 를 1,2,3 으로 표현하는 방법의 수
// 2. 관계식 - dp[i] = dp[i-3] + dp[i-2] + dp[i-1]
// 3. 기저 - dp[1] = 0, dp[2] = 1, dp[3] = 1 + 2, 2 + 1, 1 + 1 + 1

// 0 1 3 7 13 24 44 81 149 274 
int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    dp[1] = 1; dp[2] = 2; dp[3] = 4;
    for(int i = 4; i <= 10; ++i) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    cin >> T;

    while(T--) {
        cin >> N;
        cout << dp[N] << '\n';
    }

    return 0;
}