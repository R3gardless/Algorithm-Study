// 2252번 = 줄 세우기

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int a, b;
vector<pair<int, int> > vec;

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    vec.assign(N + 1, make_pair(0, 0));

    while(M--) {
        cin >> a >> b;
        vec[b].first++;
        vec[a].second = b;
    }

    

    for(int i = 1; i <= N; ++i) cout << vec[i].second << ' ';
    cout <<'\n';

    return 0;

}