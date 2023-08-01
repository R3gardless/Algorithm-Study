// 5569번 = 출근 경로

#include <iostream>
#define MOD 100000
using namespace std;

// 1. dp 정의 - dp[x][y][0] : 오른쪽 2번 이동으로 (x,y) 에 도착하는 경우의 수
// dp[x][y][1] : 위쪽 2번 이동으로 (x,y) 에 도착하는 경우의 수
// dp[x][y][2] : 위쪽 1번 오른쪽 1번 이동
// dp[x][y][3] : 오른쪽 1번 위쪽 1번 이동

// 2. 관계식  
// dp[x][y][0] = dp[x-2][y][0] + dp[x-2][y][1] + dp[x-2][y][2]
// dp[x][y][1] = dp[x][y-2][0] + dp[x][y-2][1] +dp[x][y-2][3]
// dp[x][y][2] = dp[x-1][y-1][1] + dp[x-1][y-1][3]
// dp[x][y][3] = dp[x-1][y-1][0] + dp[x-1][y-1][2] 

// 3. 기저
// do[1][n] = 1, dp[2][2][2] = 1, dp[2][2][3] = 1

int w, h;
int dp[111][111][4];

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> w >> h;

    for(int i = 2; i <= w; ++i) dp[i][1][0] = 1;
    for(int j = 2; j <= h; ++j) dp[1][j][1] = 1;

    dp[2][2][2] = 1;
    dp[2][2][3] = 1;

    for(int i = 2; i <= w; ++i) {
        for(int j = 2; j<= h; ++j) {
            if(i == 2 & j == 2) continue;
            // 오른쪽 직진
            if(i > 2) dp[i][j][0] = (dp[i-2][j][0] + dp[i-2][j][1] + dp[i-2][j][2]) % MOD;
            // 위쪽 직진
            if(j > 2) dp[i][j][1] = (dp[i][j-2][0] + dp[i][j-2][1] + dp[i][j-2][3]) % MOD;
            // 위1 오1
            dp[i][j][2] = (dp[i-1][j-1][1] + dp[i-1][j-1][3]) % MOD;
            // 오1 위1
            dp[i][j][3] = (dp[i-1][j-1][0] + dp[i-1][j-1][2]) % MOD;
        }
    }

    cout << (dp[w][h][0] + dp[w][h][1] + dp[w][h][2] + dp[w][h][3]) % MOD << '\n';

    return 0;
}