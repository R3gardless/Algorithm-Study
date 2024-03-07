// 2003번 = 수들의 합 2

#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> vec;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M;

    vec.assign(N, 0);

    for(int i = 0; i < N; ++i) cin >> vec[i];

    int s = 0, e = 0;
    int sum = 0, cnt = 0;
    while(s <= e) {
        if(e == N || sum > M) sum -= vec[s++];
        else sum += vec[e++];
        
        if(sum == M) cnt++;
    }

    cout << cnt << '\n';

    return 0;
}