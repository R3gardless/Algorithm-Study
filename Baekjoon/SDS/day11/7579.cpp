// 7579번 = 앱

#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int ans = 123456789;
int dp[100][10001];
int cost[100], memory[100];

// 1. dp 정의 - dp[i][j] = i 번째 앱까지 입력된 앱에 대해 j 비용으로 구할 수 있는 최대 메모리 크기
// 2. 관계식 - dp[i][j] = max(dp[i-1][j-cost] + memory, dp[i-1][j]) 
// cost = i번째 앱의 비활성화 비용, memory = i 번째 앱의 메모리 크기


int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < N; ++i) cin >> memory[i];
    for(int i = 0; i < N; ++i) cin >> cost[i];

    for(int i = 0; i <= 10000; ++i) { // 기저 조건
        if(i >= cost[0]) dp[0][i] = memory[0];
    }

    for(int i = 1; i < N; ++i) {
        int c = cost[i];
        int m = memory[i];
        for(int j = 0; j <= 10000; ++j) {
            if(j >= c) {
                dp[i][j] = max(dp[i-1][j-c] + m, dp[i-1][j]);
            } else dp[i][j] = dp[i-1][j];
            if(dp[i][j] >= M) ans = min(ans, j);
        }
    }
    
    cout << ans << '\n';

    return 0;

}