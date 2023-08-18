// 10423번 = 전기가 부족해

#include <iostream>
#include <tuple>
#include <algorithm>

using namespace std;

typedef tuple<int, int, int> tp;
typedef long long ll;

int N, M, K;
int k, u, v, w;
int p[1001]; // root = 발전소 여부
ll ans;
tp edge[100000]; // (a, b, c) a - b edge, c weight

int Find(int n) {
    if(p[n] < 0) return n;
    p[n] = Find(p[n]);
    return p[n];
}

void Union(int a, int b) {
    a = Find(a); b = Find(b);
    if(a == b) return; // 부모 같을 경우
    // union 하는 경우
    // 한 개의 component 에 발전소가 있는 경우
    // 모든 component 에 발전소가 없는 경우
    if(p[a] == -2 || p[b] == -2) p[a] = -2;
    p[b] = a;
}

bool compare(tp e1, tp e2) {
    return get<2>(e1) < get<2>(e2); // 오름차순 정렬
}

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> K;

    fill(p, p + N + 1, -1);

    for(int i = 0; i < K; ++i) {
        cin >> k;
        p[k] = -2; // 발전소는 -2
    }

    for(int i = 0; i < M; ++i) {
        cin >> u >> v >> w;
        edge[i] = tp(u, v, w);
    }

    sort(edge, edge + M, compare);
    for(int i = 0; i < M; ++i) {
        u = get<0>(edge[i]);
        v = get<1>(edge[i]);
        w = get<2>(edge[i]);

        if(Find(u) == Find(v)) continue;
        if(p[Find(u)] == -2 && p[Find(v)] == -2) continue; // 둘 다 component 에 발전소가 있는 경우
        Union(u, v);
        ans += w;
    }

    cout << ans << '\n';

    return 0;
}