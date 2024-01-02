// 2981번 = 검문 (unsolved)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll N;
vector<ll> vec;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;
    vec.assign(N, 0);

    for(int i = 0; i < N; ++i) cin >> vec[i];

    sort(vec.begin(), vec.end());

    for(int i = 0; i <= vec[0]; ++i) {
        
    }

    return 0;
}