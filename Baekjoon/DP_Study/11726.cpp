// 11726번 = 2xn 타일링

#include <iostream>

// 1. dp 정의 = dp[n] 2 x n 일 때 가능한 경우의 수
// 2. 관계식 = dp[n] = dp[n-1] + dp[n-2]
// 이유
// | (1개 추가) = (2개 추가) => 두 가지의 경우만 추가 가능하므로 || (| 의 중복) dp[n-1], dp[n-2] 필요
// 3. 기저 = dp[1] = 1, dp[2] = 2

int N;
int dp[1001];

using namespace std;

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    dp[1] = 1; dp[2] = 2;
    for(int i = 3; i <= N; ++i) dp[i] = (dp[i-1] + dp[i-2]) % 10007;

    cout << dp[N] << '\n';
    
    return 0;
}