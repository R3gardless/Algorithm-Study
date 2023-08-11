#include <iostream>
typedef long long ll;

using namespace std;

int N, M, K;
ll num[10000];
ll tree[20001];


int cmd, p1, S;
ll p2;

// Segment Tree Query
ll query(int left, int right, int node, int queryLeft, int queryRight) {

    if(queryRight < left || right < queryLeft) return 0;
    else if (queryLeft <= left || right <= queryRight) return tree[node];
    else {
        int mid = (left + right) / 2;
        return query(left, mid, node * 2, queryLeft, queryRight) + query(mid + 1, right, node * 2 + 1, queryLeft, queryRight);
    }
}

// Segment Tree Update
void update(int left, int right, int node, int target, ll diff) {
    if(target < left || right < target) return;
    else {
        tree[node] += diff;
        if (left != right) {
            int mid = (left + right) / 2;
            update(left, mid, node * 2, target, diff);
            update(mid + 1, right, node * 2 + 1, target, diff);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> K;

    for(int i = 0; i < N; ++i) cin >> num[i];

    S = 1;
    while(S < N) S *= 2;

    // Segment Tree Init
    for(int i = 0; i < N; ++i) {
        tree[S + i] = num[i];
    }
    for(int i = S - 1; i > 0; --i) {
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }


}