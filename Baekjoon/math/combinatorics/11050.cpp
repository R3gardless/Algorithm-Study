// 11050번 = 이항 계수 1

#include <iostream>
#define MAX 1001   
using namespace std;

int dp[MAX][MAX];
int N, K;

int main() {
    
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> K;

    for(int i = 1; i <= N; ++i) {
        dp[i][0] = 1;
        dp[i][1] = 1;
    }

    for(int i = 2; i <= N; ++i) {
        for(int j = 1; j <= i; ++j) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
    cout << dp[N][K] << '\n';

    return 0;
}