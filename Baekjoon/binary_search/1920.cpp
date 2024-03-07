// 1920번 = 수 찾기

#include <iostream>
#include <algorithm>

using namespace std;

int N, M, t, lo, hi, mid;
int arr[100000];

bool binarySearch(int target) {
    lo = 0; hi = N;

    while(lo < hi) {
        mid = (lo + hi) / 2;
        if(arr[mid] == target) return true;
        else if(arr[mid] > target) hi = mid;
        else lo = mid + 1;
    }
    return false;
}

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; ++i) cin >> arr[i];
    sort(arr, arr + N);
    cin >> M;

    for(int i = 0; i < M; ++i) {
        cin >> t;
        if(binarySearch(t)) cout << 1 << '\n';
        else cout << 0 << '\n';
    }

    return 0;

}