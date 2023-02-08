#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> v;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    v.resize(N);

    int idx;

    for(int i = 0; i < N; ++i) cin >> v[i];

    sort(v.begin(), v.end());

    idx = lower_bound(v.begin(), v.end(), 3) - v.begin(); // 3 이상의 val 가지는 처음 iterator(idx) return
                                                          // 없을 시 v.end() return

    cout << "Lower Bound : A[" << idx << "] = " << *lower_bound(v.begin(), v.end(), 3) << '\n';

    idx = upper_bound(v.begin(), v.end() , 5) - v.begin();

    cout << "Upper Bound : B[" << idx << "] = " << *lower_bound(v.begin(), v.end(), 5) << '\n'; // 5 초과의 val 가지는 처음 iterator(idx) return
                                                                                                // 없을 시 v.end() return

    if(binary_search(v.begin(), v.end(), 7)) cout << "Binary Seearch : Has 7 in Vector!" << '\n'; // True, False return
    else cout << "Binary Search : Does not have 7 in Vector!" << "\n";
}