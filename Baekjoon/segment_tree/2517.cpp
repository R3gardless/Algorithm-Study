// 2517번 = 달리기

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int N, S, n;
vector<pair<int, int>> vec;
ll tree[1048675], result[500001]; // 2^20 > 1,000,000
// (skill, index)

bool compare(const pair<int, int> & a,const pair<int, int> & b) {
    return a.first > b.first;
}

ll query(int left, int right, int node, int queryLeft, int queryRight) {
    if(queryRight < left || right < queryLeft) return 0;
    else if(queryLeft <= left && right <= queryRight) return tree[node];
    else {
        int mid = (left + right) / 2;
        return query(left, mid, node * 2, queryLeft, queryRight) + query(mid + 1, right, node * 2 + 1, queryLeft, queryRight);
    }
}


void update(int left, int right, int node, int target, ll diff) {
    if(target < left || right < target) return;
    else {
        tree[node] += diff;
        if(left != right) {
            int mid = (left + right) / 2;
            update(left, mid, node * 2, target, diff);
            update(mid + 1, right, node * 2 + 1, target, diff);
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for(int i = 1; i <= N; ++i) {
        cin >> n;
        vec.push_back(make_pair(n, i));
    }

    sort(vec.begin(), vec.end(), compare);

    S = 1;
    while(S < N) S *= 2;

    for(int i = 0; i < N; ++i) {
        // cout << vec[i].first << " " << vec[i].second << "\n";
        update(1, S, 1, vec[i].second, 1);
        result[vec[i].second] = query(1, S, 1, 1, vec[i].second);
    }

    for(int i = 1; i <= N; ++i) cout << result[i] << "\n";
    
    return 0;   
}