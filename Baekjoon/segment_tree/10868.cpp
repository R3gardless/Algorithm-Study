// 10868번 = 최솟값

#include <iostream>
#include <algorithm>
#define INF 9876543210
typedef long long ll;

using namespace std;

int N, M, S, a, b;
ll n;
ll tree[262144];

ll minQuery(int left, int right, int node, int queryLeft, int queryRight) {
    if(queryLeft > right || queryRight < left) return INF;
    else if(queryLeft <= left && right <= queryRight) return tree[node];
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

    fill(tree, tree + 2 * S, INF);

    for(int i = 0; i < N; ++i) cin >> tree[S + i];

    for(int i = S - 1; i > 0; --i) tree[i] = min(tree[i * 2], tree[i * 2 + 1]);

    for(int i = 0; i < M; ++i) {
        cin >> a >> b;
        cout << minQuery(1, S, 1, a, b) << '\n';
    }

    return 0;

}