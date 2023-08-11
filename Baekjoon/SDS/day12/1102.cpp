// 1102번 = 발전소

#include <iostream>
#include <string>
#include <algorithm>
#define INF 123456789

using namespace std;

int N, P;
int cost[16][16];
int dp[16][1<<16]; // 현재 N 개의 발전소가 켜져있고 N 개 중에 on/off 된 발전소 
string state;

int dfs(int cnt, int bit) {
    // 발전소 수리가 더 이상 필요 X
    if(cnt >= P) return 0;
    // 최소 비용이 업데이트 된 경우 리턴
    if(dp[cnt][bit] != INF) return dp[cnt][bit];

    // 반복문 돌면서 재귀 호출 탐색
    for(int i = 0; i < N; ++i) {
        // 켜져 있는 발전소 탐색
        if((bit & (1 << i)) != 0) { // 비트마스킹을 통해 최적화
            for(int j = 0; j < N; ++j) {
                // 같은 번호의 발전소이거나 j도 켜져있는 발전소 일 경우
                if(i == j || ((bit & (1 << j)) != 0)) continue;
                // 최소값 구하기
                dp[cnt][bit] = min(dp[cnt][bit], dfs(cnt + 1, bit | (1 << j)) + cost[i][j]);
            }
        }
    }
    return dp[cnt][bit];
}

int main() {
    
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cin >> cost[i][j];
        }
        for(int j = 0; j < (1 << N); ++j) {
            dp[i][j] = INF; // 최소비용 비교를 위한 DP
        }
    }

    cin >> state;
    cin >> P;

    // 발전기의 상태를 비트마스크 형태로 저장
    // OR 연산을 통해 i번째 해당하는 발전소 on
    int cnt = 0;
    int bit = 0;
    for(int i = 0; i < N; ++i) {
        if(state[i] == 'Y') {
            bit = bit | (1 << i);
            cnt++;
        }
    }
    
    int ans = dfs(cnt, bit);
    if(ans == INF) ans = -1;
    cout << ans << '\n';

    return 0;

}