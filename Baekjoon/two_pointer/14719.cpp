// 14719번 = 빗물

#include <iostream>
#include <vector>

using namespace std;

int H, W;
int sum, answer;
vector<int> v;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> H >> W;

    v.assign(W, 0);

    for(int i = 0; i < W; ++i) cin >> v[i];
    int left, right;
    left = 0; right = 1;

    for(; right < W; ++right) {
        if(v[left] <= v[right]) {
            answer += sum;
            sum = 0;
            left = right;
        } else {
            sum += v[left] - v[right];
        }
    }

    right--; sum = 0;
    while(left < right) {
        for(int i = right - 1; i >= left; --i) {
            if(v[i] < v[right]) {
                sum += v[right] - v[i];
            } else {
                right = i;
            }
        }
    }

    answer += sum;

    cout << answer << '\n';

    return 0;

}