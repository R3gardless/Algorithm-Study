// 1976번 = 여행 가자

#include <iostream>

using namespace std;

int N, M, conn, city, root;
int p[201], list[1000];

int find(int n) {
    if(p[n] < 0) return n; // component root num return
    p[n] = find(p[n]);
    return p[n];
}

void union_(int a, int b) {
    a = find(a); 
    b = find(b);
    if(a == b) return;
    p[b] = a;
}


int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    fill(p, p + N + 1, -1);

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cin >> conn;
            if(conn) union_(i + 1, j + 1); 
        }
    }

    for(int i = 0; i < M; ++i) cin >> list[i];
    root = find(list[0]);
    for(int i = 1; i < M; ++i) {
        if(find(list[i]) != root) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";

    return 0;   

}