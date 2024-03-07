// 11404번 = 플로이드

#include <iostream>
#include <algorithm>
#include <cstring>
#define INF 123456789

using namespace std;

int N, M;
int A, B, C;
int dist[101][101];

// 플로이드 워셜 구현
// 사이클 확인 불가능 => 확인하려면 벨만-포드 사용
void floydwarshall() {
    // O(V^3)
    for(int k = 1; k <= N; ++k) { // 경유하는 정점 사이클
        for(int i = 1; i <= N; ++i) { // 출발하는 정점 사이클
            for(int j = 1; j <= N; ++j) { // 도착하는 정점 사이클
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }
    
    for(int i = 0; i < M; ++i) {
        cin >> A >> B >> C;

        dist[A][B] = min(dist[A][B], C);
    }

    floydwarshall();

    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            if(dist[i][j] == INF) dist[i][j] = 0;
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;

}