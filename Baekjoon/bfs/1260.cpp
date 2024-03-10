// 1260번 = DFS와 BFS

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct cmp {
    bool operator()(int a, int b) {
        return a > b;
    };
};

int N, M, V;
int s, e;
bool visited_dfs[1001], visited_bfs[1001];

vector<int> res_dfs, res_bfs;
priority_queue<int, vector<int>, cmp> map_bfs[1001], map_dfs[1001];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs() {
    int cur, next;
    queue<int> q;

    q.push(V);
    visited_bfs[V] = true;
    while(!q.empty()) {
        cur = q.front();
        res_bfs.push_back(cur);
        q.pop();
        while(!map_bfs[cur].empty()) {
            next = map_bfs[cur].top(); map_bfs[cur].pop();
            if(visited_bfs[next]) continue;
            else {
                visited_bfs[next] = true;
                q.push(next);
            }
        }

    }
}

void dfs(int cur) {
    int next;

    res_dfs.push_back(cur);
    while(!map_dfs[cur].empty()) {
        next = map_dfs[cur].top(); map_dfs[cur].pop();
        if(visited_dfs[next]) continue;

        visited_dfs[next] = true;
        dfs(next);
    }

    visited_dfs[V] = true;

}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M >> V;

    for(int m = 0; m < M; ++m) {
        cin >> s >> e;
        map_dfs[s].push(e);
        map_dfs[e].push(s);
        map_bfs[s].push(e);
        map_bfs[e].push(s);
    }
    visited_dfs[V] = true;
    dfs(V);
    bfs();

    for(int v : res_dfs) cout << v << ' ';
    cout << '\n';

    for(int v : res_bfs) cout << v << ' ';
    cout << '\n';

    return 0;

}