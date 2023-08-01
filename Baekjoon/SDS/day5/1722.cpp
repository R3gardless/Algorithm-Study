// 1722번 = 순열의 순서

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll k, N, ans, case_num;
vector<bool> visited;
vector<ll> factorial;

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    factorial.resize(21);
    factorial[0] = 1; factorial[1] = 1;
    for(int i = 2; i <= 20; ++i) factorial[i] = factorial[i - 1] * i;
    
    cin >> N >> case_num;
    visited.assign(N + 1, false);
    if(case_num == 1) {
        bool flag = false;
        cin >> k;
        
        for(int i = 1; i <= N; ++i) {
            if(flag) break;
            for(int j = 1; j <= N; ++j) {
                if(visited[j]) continue;

                if(factorial[N - i] < k) k -= factorial[N - i];
                else if(factorial[N - i] > k) {
                    cout << j << ' ';
                    visited[j] = true;
                    break;
                } else {
                    cout << j << ' ';
                    visited[j] = true;
                    flag = true;
                    break;
                }
            }
        }

        for(int i = N; i > 0; --i) {
            if (!visited[i]) cout << i << ' ';
        }
    } else {
        for(int i = 1; i <= N; ++i) {
            int tmp;
            cin >> tmp;
            visited[tmp] = true;
            ll cnt = 0;
            for(int j = 1; j < tmp; ++j) {
                if(!visited[j]) cnt++;
            }

            ans += cnt * factorial[N - i];
        }
        cout << ans + 1 << '\n';
    }

    return 0;
}