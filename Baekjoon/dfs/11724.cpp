// 11724번 = 연결 요소의 개수

#include <iostream>
#include <vector>

using namespace std;

int N, M, s, e, res;
vector<int> map[1001];
bool visited[1001];

void dfs(int cur) {
    for(int next : map[cur]) {
        if(visited[next]) continue;
        else {
            visited[next] = true;
            dfs(next);
        }
    }
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < M; ++i) {
        cin >> s >> e;
        map[s].push_back(e);
        map[e].push_back(s);
    }

    for(int v = 1; v <= N; ++v) {
        if(visited[v]) continue;
        else {
            res++;
            dfs(v);
        }
    }

    cout << res << '\n';

    return 0;

}