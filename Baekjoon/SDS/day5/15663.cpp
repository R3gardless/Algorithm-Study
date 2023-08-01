// 15663번 = N과 M(9)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

vector<int> vec;
vector<bool> visited;
vector<int> ans;

void backtracking(int depth) {
    if(depth == M) {
        for(int i = 0; i < M; ++i) cout << ans[i] << ' ';
        cout << '\n';
        return;
    } else {
        int temp = -1;
        for(int i = 0; i < N; ++i) {
            if(visited[i] || temp == vec[i]) continue;
            visited[i] = true;
            ans[depth] = vec[i];
            temp = vec[i];
            backtracking(depth + 1);
            visited[i] = false;
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    vec.assign(N, 0);
    visited.assign(N, false);
    ans.assign(N, 0);

    for(int i = 0; i < N; ++i) cin >> vec[i];

    sort(vec.begin(), vec.end());
    backtracking(0);
}