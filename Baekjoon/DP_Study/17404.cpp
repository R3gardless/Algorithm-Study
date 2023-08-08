// 17404번 = RGB 거리 2

#include <iostream>
#include <algorithm>

using namespace std;

int N, res;
int dp[1001][3];

// 1. dp 정의 - dp[i][3] = i 번째 집을 RGB 로 색칠할 때의 minimum cost
// 2. 관계식 - dp[i][0] = 
// 3. 기저 - dp[1][0], dp[1][1], dp[1][2]

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for(int i = 1; i <= N; ++i) {
        for(int j = 0; j < 3; ++j) {
            cin >> dp[i][j];
        }
    }

    for(int i = 1; i <= N; ++i) {
        dp[i][0] += min(dp[i][1], dp[i][2]);
        dp[i][1] += min(dp[i][0], dp[i][2]);
        dp[i][2] += min(dp[i][0], dp[i][1]);
    }

    res = min({dp[N][0], dp[N][1], dp[N][2]});

    cout << res << '\n';

    return 0;
}