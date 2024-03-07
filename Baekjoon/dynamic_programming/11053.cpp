// 11053번 = 가장 긴 증가하는 부분 수열

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, max_val;
vector<int> vec;

int dp[1000];   

// 1. dp 정의 - dp[x] x 번째 일 때 가장 긴 부분수열 길이
// 2. 관계식 - dp[x] = 
// 3. 기저 - dp[1] = 1

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    memset(dp, 1, sizeof(dp));

    cin >> N;

    vec.resize(N);

    for(int i = 0; i < N; ++i) cin >> vec[i];

    max_val = vec[0];

    for(int i = 1; i < N; ++i) {
        if(vec[i] > max_val) {
            
        }
    }

    return 0;

}