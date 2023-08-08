// 1915번 = 가장 큰 정사각형

#include <iostream>
#include <algorithm>

using namespace std;

int N, M, res;
int dp[1001][1001];
char tmp;

// 1. dp 정의 - dp[i][j] = (i,j) 번째 위치에서 만들 수 있는 정사각형 변의 길이
// 2. 관계식 - dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
// 3. 기저 - input

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= M; ++j) {
            cin >> tmp; dp[i][j] = tmp - '0';
            if(dp[i][j]) {
                int tmp = min(dp[i-1][j-1], dp[i-1][j]);
                dp[i][j] += min( tmp,  dp[i][j-1] );
                res = max(res, dp[i][j]);
            }
        }
    }

    cout << res * res << '\n';

    return 0;
}