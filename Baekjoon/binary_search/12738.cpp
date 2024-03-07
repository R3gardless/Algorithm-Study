// 12738번 = 가장 긴 증가하는 부분서열 3

#include <iostream>
#include <vector>

using namespace std;

int N;
int arr[1000000];
vector<int> vec;

void binarySearch(int left, int right, int target) {
    int mid = 0;
    while(left < right) {
        mid = (left + right) / 2;
        if(target > vec[mid]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    vec[right] = target;
}

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; ++i) cin >> arr[i];

    // 1. LIS 의 마지막 숫자보다 크면 새로 추가
    // 2. LIS 의 마지막 숫자보다 작으면 적절한 위치에 삽입 > 이분탐색
    for(int i = 0; i < N; ++i) {
        if(vec.empty() || arr[i] > vec[vec.size() - 1]) {
            vec.push_back(arr[i]);
        } else {
            binarySearch(0, vec.size() - 1, arr[i]);
        }
    }

    cout << vec.size() << '\n';

    return 0;

}