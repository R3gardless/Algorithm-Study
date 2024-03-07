// 20366번 = 같이 눈사람 만들래?

#include <iostream>
#include <algorithm>
#define INF 9876543210
using namespace std;

typedef long long ll;

int N, arr[600], s, e;
ll h1, h2, res;

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    res = INF;
    for(int i = 0; i < N; ++i) cin >> arr[i];

    sort(arr, arr + N);

    for(int i = 0; i < N - 1; ++i) {
        for(int j = i + 3; j < N; ++j) {
            s = i + 1;
            e = j - 1;
            h1 = arr[i] + arr[j];
            while(s < e) {
                h2 = arr[s] + arr[e];
                if(abs(h2 - h1) < res) res = abs(h2 - h1);

                if(h2 > h1) e--;
                else s++;
                
            }
        }
    }
    cout << res << '\n';

    return 0;
}