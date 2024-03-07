// 1003번 = 피보나치 함수

#include <iostream>

using namespace std;

int dp[41][2];

// 1. dp 정의 = dp[N][0], dp[N][1] => N 일 때 0, 1 출력 회수
// 2. 관계식 = dp[N][0] = dp[N-1][0] + dp[N-2][0], dp[N][1] = dp[N-1][1] + dp[N-2][1]
// 3. 기저 = dp[0][0] = 1, dp[1][1] = 1

int T, N;

int main() {
    
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    dp[0][0] = 1; dp[1][1] = 1;
    
    for(int i = 2; i <= 40; ++i) {
        dp[i][0] = dp[i-1][0] + dp[i-2][0];
        dp[i][1] = dp[i-1][1] + dp[i-2][1];
    }

    cin >> T;

    while(T--) {
        cin >> N;
        cout << dp[N][0] << ' ' << dp[N][1] << '\n';
    }

    return 0;
}
