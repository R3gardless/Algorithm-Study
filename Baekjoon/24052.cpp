// 백준 24052번 = 알고리즘 수업 - 삽입 정렬 2

#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int N, K, j, temp, cnt;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    scanf("%d %d", &N, &K);

    v.resize(N);

    for(int i = 0; i < N; ++i) scanf("%d", &v[i]);

    for(int i = 1; i < N; ++i) {
        temp = v[i];
        j = i - 1;
        while(j >= 0 && v[j] > temp) {
            v[j+1] = v[j]; cnt++;
            j--;
            if(cnt == K) {
                for(int val : v) cout << val << ' ';
                cout << '\n';
                return 0;
            }
        }
        if(j + 1 != i) {
            v[j+1] = temp; cnt++;
            if(cnt == K) {
                for(int val : v) cout << val << ' ';
                cout << '\n';
                return 0;
            }
        }

    }
    cout << -1;
    
    return 0;
}