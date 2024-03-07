// 2357번 = 최솟값과 최댓값

#include <iostream>
#include <algorithm>
#define INF 9876543210
typedef long long ll;

using namespace std;

int N, M, S, a, b;
ll n;
pair<ll, ll> tree[262144];

ll maxQuery(int left, int right, int node, int queryLeft, int queryRight) {
    if(queryLeft > right || queryRight < left) return 0;
    else if(queryLeft <= left && right <= queryRight) return tree[node].second;
    else {
        int mid = (left + right) / 2;
        return max(maxQuery(left, mid, node * 2, queryLeft, queryRight), maxQuery(mid + 1, right, node * 2 + 1, queryLeft, queryRight));    
    }
}

ll minQuery(int left, int right, int node, int queryLeft, int queryRight) {
    if(queryLeft > right || queryRight < left) return INF;
    else if(queryLeft <= left && right <= queryRight) return tree[node].first;
    else {
        int mid = (left + right) / 2;
        return min(minQuery(left, mid, node * 2, queryLeft, queryRight), minQuery(mid + 1, right, node * 2 + 1, queryLeft, queryRight));    
    }
}


int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    S = 1;
    while(S < N) S *= 2;

    fill(tree, tree + 2 * S, make_pair(INF, 0));

    for(int i = 0; i < N; ++i) {
        cin >> n;
        tree[S + i].first = n;
        tree[S + i].second = n;
    }
    for(int i = S - 1; i > 0; --i) {
        tree[i].first = min(tree[i * 2].first, tree[i * 2 + 1].first);
        tree[i].second = max(tree[i * 2].second, tree[i * 2 + 1].second);
    }

    // for(int i = 1; i < S; ++i) {
    //     cout << tree[i].first << " " << tree[i].second << '\n';
    // }

    for(int i = 0; i < M; ++i) {
        cin >> a >> b;
        cout << minQuery(1, S, 1, a, b) << " " << maxQuery(1, S, 1, a, b) << '\n';
    }

    return 0;

}