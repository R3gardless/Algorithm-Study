// 2805번 = 나무 자르기

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int N, H;
ll lo, hi, mid, res, ans;
ll arr[1000000];


bool treeLeft(ll height) {

    ll sum = 0;
    for(int i = 0; i < N; ++i) {
        sum += max(arr[i] - height, (ll)0);
        if(sum >= H) return true;
    }
    return false;
}

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> H;

    for(int i = 0; i < N; ++i) cin >> arr[i];

    sort(arr, arr + N);

    lo = 0; hi = 1000000000;
    while(lo < hi) {
        mid = (lo + hi) / 2;
        res = treeLeft(mid);
        if(treeLeft(mid)) {
            ans = mid;
            lo = mid + 1;
        }
        else hi = mid;
    }

    cout << ans << '\n';

    return 0;

}