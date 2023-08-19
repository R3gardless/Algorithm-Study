// 2473번 = 세 용액

// 세 개의 지점에 대해 찾아야 하므로
// 1개를 고정시키고 나머지 2개에 대해서 two pointer 를 사용하여 계산
// O(N^2)

#include <iostream>
#include <tuple>
#include <algorithm>
#include <cmath>
#define INF 9876543210

using namespace std;

typedef long long ll;
typedef tuple<ll, ll, ll> tp;

ll N, arr[5000], s, e;
ll res, sum;
tp ans;

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; ++i) cin >> arr[i];

    sort(arr, arr + N);

    res = INF;
    for(int i = 0; i < N - 2; ++i) {
        s = i + 1;
        e = N - 1;
        while(s < e) {
            sum = arr[i] + arr[s] + arr[e]; // arr 을 ll 로 선언해야 하는 이유

            if(res > abs(sum)) {
                res = abs(sum);
                ans = tp(arr[i], arr[s], arr[e]);
            }

            if(res == 0) break;

            if(sum > 0) e--;
            else s++;
        }
    }

    cout << get<0>(ans) << " " << get<1>(ans) << " "  << get<2>(ans) << "\n"; 

    return 0;
}