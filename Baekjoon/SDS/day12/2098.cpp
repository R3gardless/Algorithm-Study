// 2098번 = 외판원 순회

#include <iostream>
#include <algorithm>
#define INF 987654321

using namespace std;

int N;
int map[16][16];
int dp[16][(1<<16)-1]; // dp[i][j] 현재 i의 도시에 있고 j 비트에 포함된 도시를 방문했을 때 남은 도시 방문의 최소 비용 (다시 돌아가야 함)

// 배열 초기화
// 모든 도시 탐색 : DFS 로 재귀 호출
// 모든 도시 방문했을 경우, 방문을 한 도시인 경우 조건 추가
// 현재 도시에 남은 도시 방문 비용 vs 다음 도시로

int dfs(int now, int visit) {
    // 모든 도시를 방문한 경우
    if(visit == (1 << N) - 1) {
        if(map[now][0] == 0) return INF; // 필수!
        return map[now][0]; 
    }

    // 방문을 한 도시일 경우 (dp 업데이트가 된 경우)
    if(dp[now][visit] != -1) {
        return dp[now][visit];
    }

    dp[now][visit] = INF;
    for(int i = 0; i < N; ++i) {
        // 현재 도시에서 다음 도시로 가는 길이 없거나 아니면 방문한 도시일 경우
        if(map[now][i] == 0 || (visit&(1 << i)) != 0) continue;
        
        // 현재 도시에서 남은 도시들을 방문하는 비용 vs 다음 도시로 간 다음에 다음 도시에서 남은 도시 방문하는 비용
        dp[now][visit] = min(dp[now][visit], dfs(i, visit | (1<<i)) + map[now][i]);
    }
    return dp[now][visit];
}

int main() {
    
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cin >> map[i][j];
        }
        for(int j = 0; j < (1<<N)-1; ++j) {
            dp[i][j] = -1; // 방문 안했으니 초기화
                           // INF 로 할 경우 모든 도시를 방문한 경우와 구분이 안됨
        }
    }

    cout << dfs(0, 1) << '\n';

    return 0;

}