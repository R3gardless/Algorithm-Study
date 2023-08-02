#include <iostream>
#include <tuple>
#include <algorithm>

using namespace std;
typedef tuple<int, int, int> tp;

const int MAX = 1111111;
int N, M;
int p[1001];
int ans;
tp edge[MAX]; // (a, b, c) a - b edge, c weight

int Find(int a) {
    if(p[a] < 0) return a;
    p[a] = Find(p[a]);
    return p[a];
}

void Merge(int a, int b) {
    int A = Find(a);
    int B = Find(b);
    if(A == B) return;
    p[B] += p[A]; // 해당 component 크기 저장
    p[A] = B;
}

bool cmp(tp e1, tp e2) {
    return get<2>(e1) < get<2>(e2);
}
int main() {
    cin >> N >> M;
    for(int i = 1; i <= N; ++i) p[i] = -1;

    for(int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        edge[i] = tp(a, b, c);
    }
    sort(edge, edge + M, cmp);
    for(int i = 0; i < M; ++i) {
        int u = get<0>(edge[i]);
        int v = get<1>(edge[i]);
        int w = get<2>(edge[i]);

        if(Find(u) == Find(v)) continue;
        Merge(u, v);
        ans += w;

        if(p[Find(v)] == -N) break;
    }
    cout << ans << '\n';

    return 0;
}

