// 1275번 = 커피숍2

#include <iostream>
typedef long long ll;

using namespace std;

int N, Q, S, x, y, a, b;
ll tree[262144];

ll query(int left, int right, int node, int queryLeft, int queryRight) {
    if(queryRight < left || right < queryLeft) return 0;
    else if(queryLeft <= left && right <= queryRight) return tree[node];
    else {
        int mid = (left + right) / 2;
        return query(left, mid, node * 2, queryLeft, queryRight) + query(mid + 1, right, node * 2 + 1, queryLeft, queryRight);
    }
}

void update(int left, int right, int node, int target, ll diff) {
    if(target < left || target > right) return;
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

    cin >> N >> Q;

    S = 1;
    while(S < N) S *= 2;

    for(int i = 0; i < N; ++i) cin >> tree[S + i];
    for(int i = S -1 ; i> 0; --i) tree[i] = tree[i* 2] + tree[i* 2 + 1];

    for(int i = 0; i < Q; ++i) {
        cin >> x >> y >> a >> b;
        if(x > y) cout << query(1, S, 1, y, x) << '\n';
        else cout << query(1, S, 1, x, y) << '\n';
        update(1, S, 1, a, b - tree[S + a - 1]);
    }

    return 0;
}