// 2839번 = 설탕 배달

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N;

int dp[5001];

// 1. dp 정의 - dp[i] i 무게 일 때 필요한 봉지 최소의 개수
// 2. 점화식 - dp[i] = min(dp[i-3], dp[i-5]) + 1
// 3. 기저 - dp[3] = 1, dp[5] = 1

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    memset(dp, -1, sizeof(dp));

    dp[3] = 1; dp[5] = 1;

    for(int i = 6; i <= N; ++i) {
        if(dp[i-3] == -1 && dp[i-5] == -1) dp[i] = -1;
        else if(dp[i-3] == -1) dp[i] = dp[i-5] + 1;
        else if(dp[i-5] == -1) dp[i] = dp[i-3] + 1;
        else dp[i] = min(dp[i-3], dp[i-5]) + 1;
    }

    cout << dp[N] << '\n';

    return 0;
}   