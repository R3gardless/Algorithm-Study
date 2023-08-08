// 10844번 = 쉬운 계단 수

#include <iostream>

typedef long long ll;

using namespace std;

int N;
ll dp[101][10];
ll res;

// 1. dp 정의 - dp[x][n] = 길이가 x 일 때 n 으로 끝나는 계단 수 갯수 
// 2. 관계식 
// dp[x][i] = dp[x-1][i-1] + dp[x-1][i+1]
// i 가 0 혹은 9 일때 예외 처리
// 3. 기저 - dp[1][1~9] = 1

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    
    for(int i = 1; i <= 9; ++i) dp[1][i] = 1;

    for(int i = 2; i <= N; ++i) {
        for(int j = 1; j <= 8; ++j) {
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % 1000000000;
        }
        dp[i][0] = dp[i-1][1];
        dp[i][9] = dp[i-1][8];
    }

    for(int i = 0; i <= 9; ++i) {
        res = (res + dp[N][i]) % 1000000000;
    }

    cout << res << '\n';

    return 0;

}