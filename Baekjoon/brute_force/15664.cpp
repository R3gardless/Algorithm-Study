// 15664번 = N과 M (10)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;

vector<int> vec;
vector<int> visited;
vector<int> ans;

void backtracking(int depth, int index) {
    if(depth == M) {
        for(int i = 0; i < M; ++i) cout << ans[i] << ' ';
        cout << '\n'; 
        return;
    } else {
        int last = -1;
        for(int idx = index; idx < N; ++idx) {
            if(visited[idx] || last == vec[idx]) continue;
            visited[idx] = true;
            last = vec[idx];
            ans[depth] = vec[idx];
            backtracking(depth + 1, idx + 1);
            visited[idx] = false;
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

    backtracking(0, 0);

    return 0;
}   