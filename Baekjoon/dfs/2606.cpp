// 2606번 = 바이러스

#include <iostream>
#include <vector>

using namespace std;

int V, E, s, e, res;
vector<int> map[101];
bool visited[101];

void dfs(int cur) {
    int next;

    for(int v : map[cur]) {
        if(visited[v]) continue;
        visited[v] = true; res++;
        dfs(v);
    }

}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> V >> E;

    for(int i = 0; i < E; ++i) {
        cin >> s >> e;
        map[s].push_back(e);
        map[e].push_back(s);
    }

    visited[1] = true;
    dfs(1);

    cout << res << '\n';

    return 0;

}