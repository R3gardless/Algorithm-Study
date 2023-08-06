// 2579번 = 계단 오르기

#include <iostream>
#include <algorithm>

using namespace std;

int N, n;
int dp[301][2];

// 1. dp 정의 - dp[x][0], dp[x][1] = x 계단에 있을 때 연속된 횟수 0, 1 일 때 최대값
// 2. 관계식 - dp[i][0] += max(dp[i-2][0], dp[i-2][1]), dp[i][1] += dp[i-1][0]
// 3. 기저 - dp[i][0] = dp[i][1] = n, dp[1][1] = 0

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for(int i = 1; i <= N; ++i) {
        cin >> n;
        dp[i][0] = n; dp[i][1] = n;
    }

    dp[1][1] = 0;

    for(int i = 2; i <= N; ++i) {
        dp[i][0] += max(dp[i-2][0], dp[i-2][1]);
        dp[i][1] += dp[i-1][0];
    }

    cout << max(dp[N][1], dp[N][0]) << '\n';

    return 0;

}