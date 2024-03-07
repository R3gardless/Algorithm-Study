// 11657번 = 타임머신

#include <iostream>
#include <vector>
#define INF 1234567890

typedef long long ll;

using namespace std;

struct Edge {
    int to;
    int cost;
    Edge(int to1, int cost1) : to(to1), cost(cost1) {}
};

int N, M;
int A, B, C;
ll dist[501];
bool isCycle;
vector<Edge> adjList[501];
// 벨만-포드는 모든 정점을 순회하므로 priority_queue 필요 X

// 벨만-포드 알고리즘
void bellmanFord() {
    dist[1] = 0;
    for(int i = 1; i < N; ++i) { // N - 1 탐색 사이클 횟수
        for(int j = 1; j <= N; ++j) { // 모든 정점에서 갈 수 있는 간선 탐색 횟수
            for(Edge next : adjList[j]) {
                if(dist[next.to] > dist[j] + next.cost && dist[j] != INF) { // 최단 경로 비교
                    // 모든 간선 탐색
                    // dist[j] != INF => 아직 탐색되지 않은 간선, 중복 방지
                    dist[next.to] = dist[j] + next.cost;
                }
            }
        }
    }
    for(int j = 1; j <= N; ++j) { // 모든 정점에서 갈 수 있는 간선 탐색 횟수
        for(Edge next : adjList[j]) {
            if(dist[next.to] > dist[j] + next.cost && dist[j] != INF) { // 최단 경로 비교
                isCycle = true; // 음수 싸이클 존재
                return;
            }
        }
    }
}

// 1. 출발 노드 설정
// 2. 최단 거리 테이블 초기화
// 3. 모든 간선 M 개를 하나씩 전부 탐색 후 업데이트(N-1 번 수행)
// 3-2. 만약 음수 간선 존재 유무 파악 시, 3번 한 번 더 수행 -> Dist 업데이트 발생 시 음수 사이클 존재

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    fill(dist, dist+501, INF);

    for(int i = 0; i < M; ++i) {

        cin >> A >> B >> C;

        adjList[A].push_back(Edge(B, C));
    }

    bellmanFord();

    if(isCycle) {
        cout << -1 << '\n'; // 어떤 도시로 가는 과정에서 시간을 무한히 오래 전으로 되돌릴 수 있는 경우
    } else {
        for(int i = 2; i <= N; ++i) {
            if(dist[i] == INF) cout << -1 << '\n';
            else cout << dist[i] << '\n';
        }
    }
    
    return 0;
}