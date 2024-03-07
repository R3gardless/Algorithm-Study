// 11062번 = 카드 게임

#include <iostream>
#include <algorithm>
#define INF 123456789

using namespace std;

int T, N, C;
int cardList[1001];
int dp[1001][1001]; // dp[i][j] i~j 번째 카드가 남았을 때 근우가 얻을 수 있는 최대 점수
bool finalTurn; // 마지막 turn 이 근우일 경우

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> T;

    while(T--) {
        cin >> N;
        for(int i = 1; i <= N; ++i) cin >> cardList[i];
        for(int i = 1; i <= N; ++i) {
            for(int j = 1; j <= N; ++j) dp[i][j] = 0;
        }

        if(N%2 == 1) finalTurn = true;


        for(int i = 1; i <= N; ++i) {
            for(int j = 1; j <= N - i + 1; ++j) {
                int row = j; int col = i + j - 1; // 대각선 접근
                if(finalTurn) { // 최대한 DP 를 크게 업데이트
                    dp[row][col] = max(dp[row+1][col] + cardList[row], dp[row][col-1] + cardList[col]);
                } else { // 명우 차례에는 최대한 작게
                    dp[row][col] = min(dp[row+1][col], dp[row][col-1]);
                }
            }
            finalTurn = !finalTurn;
        }
        cout << dp[1][N] << '\n';

    }
}