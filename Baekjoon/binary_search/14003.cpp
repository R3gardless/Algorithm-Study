// 14003번 = 가장 긴 증가하는 부분 수열 5

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N;
int arr[1000000];
int lis_index[1000000];
vector<int> vec;
stack<int> st;

void binarySearch(int left, int right, int target, int now) {
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
    lis_index[now] = right;
}

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; ++i) cin >> arr[i];

    // 1. LIS 의 마지막 숫자보다 크면 새로 추가
    // 2. LIS 의 마지막 숫자보다 작으면 적절한 위치에 삽입 > 이분탐색
    // 3. 위 과정을 진행하면서 인덱스 정보도 기록
    for(int i = 0; i < N; ++i) {
        if(vec.empty() || arr[i] > vec[vec.size() - 1]) {
            vec.push_back(arr[i]);
            lis_index[i] = vec.size() - 1;
        } else {
            binarySearch(0, vec.size() - 1, arr[i], i);
        }
    }

    int lis_len = vec.size() - 1;
    for(int i = N-1; i>=0; --i) {
        if(lis_index[i]==lis_len) {
            lis_len--;
            st.push(arr[i]);
        }
    }

    cout << vec.size() << '\n';

    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    cout << '\n';
    return 0;

}