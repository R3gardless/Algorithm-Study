// 1932번 = 정수 삼각형

#include <iostream>
#include <algorithm>

using namespace std;

int N;
int res = -1;
int dp[502][502];

// 1. dp 정의 - dp[x][i] = x번째 줄 i번째 최대가 되는 경로
// 2. 관계식 - dp[x][i] += max(dp[x-1][i-1], dp[x-1][i])
// 3. 기저 - dp[1][1]

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for(int i = 1; i<= N; ++i) {
        for(int j = 1; j <= i; ++j) {
            cin >> dp[i][j];
            dp[i][j] += max(dp[i-1][j-1], dp[i-1][j]);
            res = max(res, dp[i][j]);
        }
    }

    cout << res << '\n';

    return 0;
}