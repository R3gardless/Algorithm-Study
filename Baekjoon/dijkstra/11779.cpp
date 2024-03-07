// 11779번 = 최소비용 구하기2

#include <iostream>
#include <queue>
#include <vector>
#define INF 123456789

using namespace std;

struct Edge {
    int to;
    int cost;
    Edge(int to1, int cost1) : to(to1), cost(cost1) {}
};

struct compare {
    bool operator() (const Edge & e1, const Edge & e2) {
        return e1.cost < e2.cost;
    }
};

int N, M;
int S, E, W;
int dist[1001];
int path[1001];
int visited[1001];
vector<Edge> adjList[1001];
priority_queue<Edge, vector<Edge>, compare> pq;


void findPath(int v) {
    if(v == S) {
        cout << v << " ";
        return;
    } else {
        findPath(path[v]);
        cout << v << " ";
    }
}

void dijkstra() {

    pq.push(Edge(S, 0));
    dist[S] = 0;

    while(!pq.empty()) {
        Edge cur = pq.top(); pq.pop();

        if(dist[cur.to] < cur.cost) continue; // 거리 갱신 필요 X

        for(Edge next : adjList[cur.to]) {
            if(dist[next.to] > dist[cur.to] + next.cost) {
                dist[next.to] = dist[cur.to] + next.cost;
                path[next.to] = cur.to;
                visited[next.to] = visited[cur.to] + 1;
                pq.push(Edge(next.to , dist[next.to]));
            }
        }
    }

}


int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    fill(path, path + 1001, -1);
    fill(visited, visited + 1001, 1);
    fill(dist, dist + 1001, INF);

    for(int i = 0; i < M; ++i) {
        cin >> S >> E >> W;
        adjList[S].push_back(Edge(E, W));
    }

    cin >> S >> E;

    dijkstra();

    cout << dist[E] << '\n';
    cout << visited[E] << '\n';
    findPath(E);

    return 0;
}