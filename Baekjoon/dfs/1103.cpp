// 1103번 = 게임

#include <iostream>
using namespace std;

bool isINF;
int N, M, res;
char ch, map[50][50];
bool visited[50][50];
int dist[50][50];

int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

// 오답노트

// 특정 지점을 방문했다고 최대 이동거리를 의미하는 것이 아님 (dfs 탐색 순서에 따라 다름)
// 진정한 재귀 탐색

int dfs(int curY, int curX) {

    if(curY < 0 || curY >= N || curX < 0 || curX >= M || map[curY][curX] == 'H') return 0; // 더 이상 이동하지 않는 경우
    if(visited[curY][curX]) { // 이미 방문되었던 경우 => 무한히 반복 가능
        cout << "-1\n";
        exit(0);
    }
    if(dist[curY][curX] != -1) return dist[curY][curX]; // 이미 방문되었떤 지점인 경우 dist에 저장되었던 값 return

    visited[curY][curX] = true; // 방문 여부 업데이트
    dist[curY][curX] = 0; // 현재 지점을 시점으로 recursive 하게 search

    int move = map[curY][curX] - '0';
    int nextY, nextX;
    for(int i = 0; i < 4; ++i) {
        nextY = curY + move * dy[i]; nextX = curX + move * dx[i];
        dist[curY][curX] = max(dist[curY][curX], dfs(nextY, nextX) + 1); // recursive 하게 상하좌우 search
    }

    visited[curY][curX] = false; // 방문 여부 초기화
    return dist[curY][curX]; // recursive하게 return
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            cin >> map[i][j];
            dist[i][j] = -1;
        }
    }
    
    dfs(0, 0);

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            res = dist[i][j] > res ? dist[i][j] : res;
        }
    }

    cout << res << '\n';
    
    
    return 0;
}