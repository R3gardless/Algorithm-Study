// 2449번 = 전구

#include <iostream>
#define INF 123456789

using namespace std;

int N, K;
int dp[201][201]; // dp[i][j] = i~j 전구까지 색깔을 하나로 통일하는 데 드는 최소 비용
int bulb[201];

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;

    // 같은 색깔의 전구는 하나로 묶어 입력받기
    for(int i = 1; i <= N; ++i) {
        cin >> bulb[i];
        if(bulb[i] == bulb[i-1]) {
            N--;
            i--;
        }
    }

    // DP 배열 초기화
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <=N; ++j) {
            dp[i][j] = INF;
        }
        dp[i][i] = 0;
    }

    // 두 개 이상의 전구들 간의 최솟값 계산 -> 사이즈 증가
    // 중간 지점 K 앞 뒤 전구 색깔이 다를 경우  
    // 중간 지점 K 앞 뒤 전구 색깔이 같을 경우
    // dp[i][j] = max(dp[i][k] + dp[k+1][j] + 1)
    for(int size = 2; size <= N; ++size) {
        for(int start = 1; start <= N - size + 1; ++start) {
            int end = start + size - 1;
            for(int k = start; k <= end; ++k) {
                int tmp = dp[start][k] + dp[k+1][end];
                if(bulb[start] != bulb[k+1]) tmp++;
                dp[start][end] = min(dp[start][end], tmp);
            }
        }
    }

    cout << dp[1][N] << '\n';

    return 0;
}