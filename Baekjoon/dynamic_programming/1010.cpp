// 1010번 다리 놓기

#include <iostream>

using namespace std;

int N, M, T;
int dp[30][30];

// 어떻게 정의할 것인가
// 관계식이 무엇인가
// 기저를 어떻게 놓을 것 인가? (초기값)

// 조합 문제

int main() {
    
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> T;

    while(T--) {
        int answer = 1;
        int temp = 1;
        cin >> N >> M;

        for(int i = M; i > M - N; --i) {
            answer *= i;
            answer /= temp++;
        }

        cout << answer << '\n';
    }

    return 0;
}