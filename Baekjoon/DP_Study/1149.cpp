// 1149번 = RGB 거리

#include <iostream>
#include <algorithm>

using namespace std;

// 1. dp 정의 - dp[x][0], dp[x][1], dp[x][2] = x 번째 집을 RGB 각각 색칠할 때의 최소값
// 2. 관계식 - dp[x][0] += min(dp[x][1], dp[x][2])
// 3. 기저 - dp[1][0], dp[1][1], dp[1][2]

int N, r, g, b;
int dp[1001][3];

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for(int i = 1; i <= N; ++i) {
        cin >> r >> g >> b;

        dp[i][0] = r; dp[i][1] = g; dp[i][2] = b;
    }

    for(int i = 2; i <= N; ++i) {

        dp[i][0] += min(dp[i-1][1], dp[i-1][2]);
        dp[i][1] += min(dp[i-1][0], dp[i-1][2]);
        dp[i][2] += min(dp[i-1][0], dp[i-1][1]);
    }
    int res = dp[N][0] > dp[N][1] ? dp[N][1] : dp[N][0];
    cout << min(res, dp[N][2]) << '\n';

    return 0;

}