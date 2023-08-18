// 1368번 = 물대기

#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>

using namespace std;

typedef tuple<int, int, int> tp; // u, v, w;
typedef long long ll;

int N, W;
int u, v, w;
int p[301], cost[300];
vector<tp> edge;
ll ans;

bool compare(tp & e1, tp & e2) {
    return get<2>(e1) < get<2>(e2);
}

int Find(int n) {
    if(p[n] < 0) return n;
    p[n] = Find(p[n]);
    return p[n];
}

void Union(int a, int b) {
    a = Find(a); b = Find(b);
    if(a == b) return;
    p[a] += p[b];
    p[b] = a;
}


int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    fill(p, p + N, -1);
    for(int i = 0; i < N; ++i) {
        cin >> cost[i];
    }

    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            cin >> W;
            if(i >= j) continue;
            edge.push_back(tp(i, j, W));
        }
    }

    sort(cost, cost + N);
    sort(edge.begin(), edge.end(), compare);
    ans += cost[0];
    
    for(int i = 0; i < edge.size(); ++i) {
        u = get<0>(edge[i]);
        v = get<1>(edge[i]);
        w = get<2>(edge[i]);

        if(Find(u) == Find(v)) continue;
        Union(u, v);
        ans += w;

        if(p[Find(u)] == -N) break;

    }

    cout << ans << '\n';

    return 0;
}