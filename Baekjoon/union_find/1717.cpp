// 1717번 = 집합의 표현

#include <iostream>
#include <vector>
using namespace std;

int N, M, C;
int a, b;
vector<int> p;

int find(int n) {
    if(p[n] < 0) return n;
    p[n] = find(p[n]);
    return p[n];
}

void union_(int a, int b){ 

    a = find(a);
    b = find(b);
    if(a == b) return;
    p[a] = b;
}

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    p.assign(N + 1, -1);

    while(M--) {
        cin >> C >> a >> b;

        if(C == 0) { // Union
            union_(a, b);
        } else { // Find
            if(find(a) == find(b)) cout << "YES\n";
            else cout << "NO\n";
        }

    }
    return 0;
}