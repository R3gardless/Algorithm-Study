// 5568번 = 카드 놓기

#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

int N, K, n;
vector<int> vec;
vector<int> answer;
vector<bool> used;
unordered_set<int> res_set;

void backtracking(int depth, int val) {
    if(depth == K) {
        res_set.insert(val);
        return;
    } else {
        for(int i = 0; i < N; ++i) {
            if(used[i]) continue;
            used[i] = true;
            int digit = vec[i] >= 10 ? 100 : 10;
            backtracking(depth + 1, val * digit + vec[i]);
            used[i] = false;
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;
    used.assign(N, false);
    answer.resize(K);
    for(int i = 0; i < N; ++i) {
        cin >> n;
        vec.push_back(n);
    }


    backtracking(0, 0);

    cout << res_set.size() << '\n';
    return 0;

}