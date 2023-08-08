// 1753번 = 최단경로

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define INF 200001

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

int V, E, S;
int u, v, w;
int dist[20001];
vector<Edge> adjList[20001]; // dijkstra 는 인접 행렬보단 인접 리스트 구현이 어렵지만 성능 측면에서 좋음
// dijsktra 는 다른 최단 경로 알고리즘 벨만-포드, 플로이드-워셜에 비해 변형 문제 많음
priority_queue<Edge, vector<Edge>, compare> pq;

// 다익스트라 구현
void dijkstra() {
    pq.push(Edge(S, 0));
    dist[S] = 0;

    while(!pq.empty()) {
        Edge cur = pq.top(); // 최소 비용을 가진 간선 정보 꺼내기
        pq.pop();

        if(dist[cur.to] < cur.cost) continue; // 거리 갱신이 필요 없는 경우

        for(Edge next : adjList[cur.to]) { // 현재 노드와 연결된 다른 인접한 노드들 확인
            if(dist[next.to] > dist[cur.to] + next.cost) { // 현재 노드를 거쳐서 다른 노드로 이동하는 거리가 더 짧은 경우
                dist[next.to] = dist[cur.to] + next.cost;
                pq.push(Edge(next.to, dist[next.to]));
            }
            
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    fill(dist, dist + 20001, INF);

    cin >> V >> E >> S;

    for(int i = 0; i < E; ++i) {

        cin >> u >> v >> w;
        adjList[u].push_back(Edge(v, w));
    }

    dijkstra();

    for(int i = 1; i <= V; ++i) {
        if(dist[i] == INF) cout << "INF" << '\n';
        else cout << dist[i] << '\n';
    }

    return 0;
}