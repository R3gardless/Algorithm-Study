// 2470번 = 두 용액

#include <iostream>
#include <algorithm>
#include <cmath>
#define INF 9876543210

using namespace std;
typedef long long ll;

int N;
int arr[100000];
ll sum, res;
pair<int, int> ans;

// 투 포인터 전략
// 1. 주어진 배열의 순서 영향 有 -> 자연수
// 2. 주어진 배열의 순서 영향 無 -> 정렬해서 쓰면 됨 (일정 값 갖는 부분합)

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; ++i) cin >> arr[i];

    int s = 0, e = N - 1;
    res = INF;
    sort(arr, arr + N);
    while(s < e) {
        sum = arr[s] + arr[e];

        if(res > abs(sum)) {
            res = abs(sum);
            ans.first = arr[s];
            ans.second = arr[e];
        }

        if(sum == 0) break;

        if(sum > 0) e--;
        else s++;

    }

    cout << ans.first << " " << ans.second << '\n';

    return 0;

}
