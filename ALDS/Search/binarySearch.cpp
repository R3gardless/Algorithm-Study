#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, T, q;

vector<int> v;

int binarySearch(int k) {
    int left = 0, right = N, mid; // right = max_idx + 1

    while(left < right) {
        mid = (left + right) / 2;
        if(v[mid] == k) return mid;
        
        if(v[mid] < k) left = mid + 1;
        else right = mid; // right = max_idx + 1
    }

    return -1;
}

int main() {
    
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    v.resize(N);

    for(int i = 0; i < N; ++i) cin >> v[i];

    sort(v.begin(), v.end());

    int cnt = 0;

    cin >> T;

    while(T--) {
        cin >> q;
        if(binarySearch(q) != -1) cnt++;
    }

    cout << cnt << '\n';

    return 0;
}