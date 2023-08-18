// 2243번 = 사탕상자

#include <iostream>
#define MAX 1000000
typedef long long ll;

using namespace std;

int n, A, B, C;
ll S;
ll tree[2097152];

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

void query(int node, int rank) {
    if(node >= S) {
        int res = node - S + 1;
        update(1, S, 1, res, -1);
        cout << res << '\n';
        return;
    }
    if(rank > tree[node * 2]) query(node * 2 + 1, rank -= tree[node * 2]);
    else query(node * 2, rank); 
}

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    S = 1;
    while(S < MAX) S *= 2;

    cin >> n;

    while(n--) {

        cin >> A >> B;

        if(A == 1) { // 사탕 빼기
            query(1, B); // rank에 해당하는 사탕 찾기
        } else { // 사탕 넣기 + 빼기
            cin >> C;
            update(1, S, 1, B, C);
        }
    }

    return 0;

}