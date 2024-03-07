// 11659번 = 구간 합 구하기 4

#include <iostream>

using namespace std;

int N, M, i, j;
int dp[100001];

// 1. dp 정의 - 

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for(int i = 1; i<= N; ++i) cin >> dp[i];
    
    for(int i = 2; i <= N; ++i) {
        dp[i] += dp[i-1];
    }

    while(M--) {
        cin >> i >> j;
        cout << dp[j] - dp[i-1] << '\n';
    }

    return 0;

}