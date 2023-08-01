// 5573번 = 산책

#include <iostream>

using namespace std;

int H, W, N;
int arr[1111][1111];
// dp[x][y] : (x, y)  교차로를 지나간 횟수 (1~N-1 경로를 지나며)
int dp[1111][1111];

// 1 ~ N - 1 해당 좌표 몇 번 밟혔는 지 알 수 있으면 N 번째 경로 확인 가능
// 1. DP 정의 - dp[i][j] : 1, 2, ..., N - 1 경로 -> (i, j) 방문 횟수 
// 2. 관계식 - 코드 참고 (자신의 왼쪽, 위쪽 좌표에 영향을 받음)
// 3. 기저 - dp[1][1] = N

void GetPath(int x = 1, int y = 1) {
    // 종료되는 교차로
    if (x > H || y > W) {
        cout << x << ' ' << y << '\n';
        return;
    }
    if (arr[x][y] == 0) GetPath(x + 1, y);
    else GetPath(x, y + 1);
}


int main() {
    
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> H >> W >> N;
    // 0: 아래쪽, 1: 오른쪽
    for(int i = 1 ; i<= H; ++i)
        for(int j = 1; j <= W; ++j)
            cin >> arr[i][j];
    
    // N-1번 산책할 때 각 교차로가 몇 번 지나게 되는 지
    dp[1][1] = N - 1;
    for(int i = 1; i <= H; ++i) {
        for(int j = 1; j <= W; ++j) {
            int val = dp[i][j];

            if(arr[i][j] == 1) { // (i,j) 교차로에 '오' 일 경우
                // 자신의 오른쪽
                dp[i][j+1] += (val / 2) + (val % 2);
                // 자신의 아래쪽
                dp[i+1][j] += (val / 2);
            }
            // '아' 일 경우
            else {
                dp[i][j+1] += (val / 2);

                dp[i+1][j] += (val / 2) + (val % 2);
            }
        }
    }
    // 교차로의 N 번째 방향 시작 직전 (N-1번 방문)
    // dp 값 mod 2 -> 0이면 초기 방향 그대로, 1이면 바뀜
    for(int i = 1; i <= H; ++i) {
        for(int j = 1; j <= W; ++j) {
            arr[i][j] = (arr[i][j] + (dp[i][j] % 2)) % 2;
        }
    }
    GetPath(1, 1);
    return 0;
}