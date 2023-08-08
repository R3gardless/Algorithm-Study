// 2579번 = 계단 오르기

#include <iostream>

using namespace std;

int N;
int dp[301], step[301];

// 1. dp 정의 - i번째 계단을 올랐을 때 최대 점수
// 2. 관계식 - dp[i] = max(dp[i-3] + step[i-1], dp[i-2]) + step[i]
// i 직전 계단 (i - 1) 계단을 밟았는 지 여부에 따라 나눔
// 3. 기저 - dp[1] = step[1], dp[2] = step[1] + step[2]

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for(int i = 1; i <= N; ++i) cin >> step[i];
    dp[1] = step[1];
    dp[2] = step[1] + step[2];
    for(int i = 3; i <= N; ++i) {
        dp[i] = max(step[i-1] + dp[i - 3], dp[i - 2]) + step[i];
    }

    cout << dp[N] << '\n';

    return 0;
}

