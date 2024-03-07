// 11727번 = 2xn 타일링 2

#include <iostream>

using namespace std;

int dp[1001];
int N;

// 1. dp 정의 - dp[n] = 2xn 일 때 가능한 경우의 수
// 2. 관계식 - dp[n] = dp[n-1] + 2 * dp[n-2] 
// 이유 
// 11726번에 2x2 타일이 추가되서 2x2 인 타일이 추가 될 경우의 수가 2개임.
// 3. 기저 - dp[1] = 1, dp[2] = 3

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    dp[1] = 1;
    dp[2] = 3;

    cin >> N;

    for(int i = 3; i <= N; ++i) {
        dp[i] = (dp[i-1] + 2 * dp[i-2]) % 10007;
    }

    cout << dp[N] << '\n';

    return 0;
}