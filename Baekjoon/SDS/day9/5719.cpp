// 5719번 = 거의 최단 경로

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define INF 500001


using namespace std;

struct Edge {
    int to;
    int cost;
    Edge(int to1, int cost1) : to(to1), cost(cost1) {}
};

struct compare {
    bool operator() (const Edge & e1, const Edge & e2) {
        return e1.cost > e2.cost;
    }
};

int N, M;
int S, D;
int U, V, P;
bool visited[500][500]; // visited[i][j] = i 에서 j 까지 경로의 존재 여부 확인
int dist[500];
vector<int> shortestPath[500];
vector<Edge> adjList[500];
priority_queue<Edge, vector<Edge>, compare> pq;

// 다익스트라를 통해 최단 경로 추적 = 최단 경로 추적을 위해 별도의 리스트 필요
// 1. 간선 정보 인접리스트에 저장
// 2. 첫 번째 1차 다익스트라를 통해 구해줌 = 최단 경로에 해당되는 간선 추적 후 저장
// 3. 추적한 간선에 대한 정보 활용하여 boolean 배열 탐색 불가하도록 true 처리
// 4. 다익스트라 수행해서 최단 경로 재탐색
// 5. dist[] 원하는 특정 정점으로의 거의 최단 경로 저장 => 출력

// 다익스트라 구현
void dijkstra() {
    pq.push(Edge(S, 0));
    dist[S] = 0;

    while(!pq.empty()) {
        Edge cur = pq.top(); // 최소 비용을 가진 간선 정보 꺼내기
        pq.pop();

        if(dist[cur.to] < cur.cost) continue; // 거리 갱신이 필요 없는 경우

        for(Edge next : adjList[cur.to]) { // 현재 노드와 연결된 다른 인접한 노드들 확인
            if(visited[cur.to][next.to]) continue; // 최단 경로 제외

            if(dist[next.to] > dist[cur.to] + next.cost) { // 현재 노드를 거쳐서 다른 노드로 이동하는 거리가 더 짧은 경우
                dist[next.to] = dist[cur.to] + next.cost;
                shortestPath[next.to].clear();
                shortestPath[next.to].push_back(cur.to); // 최단 경로가 업데이트 되는 경우 해당 간선 추가
                pq.push(Edge(next.to, dist[next.to]));
            } else if(dist[next.to] == dist[cur.to] + next.cost) { // 최단 경로 같은 경우
                shortestPath[next.to].push_back(cur.to); // pq 에 갱신 할 필요 X
            }
            
        }
    }
}

void removeShortestPath(int start, int end) {
    if(start == end) return;
    for (int next : shortestPath[end]) {
        if(!visited[next][end]) {
            visited[next][end] = true;
            removeShortestPath(start, next);
        }
    }
}
int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    while(true) {
        cin >> N >> M;
        if(N == 0 && M == 0) break;
        cin >> S >> D;

        // 0. 초기화
        memset(visited, false, sizeof(visited));
        for(int i = 0; i < 500; ++i) {
            shortestPath[i].clear(); adjList[i].clear();
        }

        for(int i = 0; i < M; ++i) {
            cin >> U >> V >> P;
            adjList[U].push_back(Edge(V, P));
        }

        // 1. 최단 경로 탐색
        fill(dist, dist + 500, INF);
        dijkstra();

        // 2. 최단 경로 제외
        removeShortestPath(S, D);

        // 3. 최단 경로 재탐색
        fill(dist, dist + 500, INF);
        dijkstra();

        if(dist[D] == INF) cout << "-1" << '\n';
        else cout << dist[D] << '\n';

    }
    
    return 0;

}