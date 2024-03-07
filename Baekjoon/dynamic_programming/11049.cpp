// 11049번 = 행렬 곱셈 순서

// 사선 DP
#include <iostream>
#include <algorithm>
#define INF 123456789

using namespace std;

int N;
int mat[500][2]; // mat[i][0] : i 번째 행렬의 행의 크기,, mat[i][1] : i 번째 행렬의 열의 크기
int dp[500][500];

// 관계식 = 이전 

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; ++i) {
        cin >> mat[i][0] >> mat[i][1];
    }

    // dp[i][j] : i 부터 j 까지 곱했을 때 최적의 값
    // dp[i][j] = d[i][k] + d[k+1][j], i~k 행렬과 k+1 ~ j 행렬
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            dp[i][j] = INF;
        }
        dp[i][i] = 0;
    }

    // dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + mat[i][0] * mat[k][1] * mat[j][1])
    // FloydWarshall 과 비슷한 의미 (경유, 출발, 도착))
    for(int size = 2; size <= N; ++size) {
        for(int start = 0; start < N - size + 1; ++start) {
            int end = start + size - 1;
            for(int k = start; k < end; ++k) {
                dp[start][end] = min(dp[start][end], dp[start][k] + dp[k+1][end] + mat[start][0] * mat[k][1] * mat[end][1]);
            }
        }
    }

    cout << dp[0][N-1] << '\n';

    return 0;
}