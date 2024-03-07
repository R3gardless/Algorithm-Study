// 백준 24051번 = 알고리즘 수업 - 삽입 정렬 1

#include <iostream>
#include <vector>

using namespace std;

int N, K, cnt, res;
int temp, j;

vector<int> v;

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
            if(cnt == K) res = v[j+1];
        }
        if(j + 1 != i) {
            v[j+1] = temp; cnt++;
            if(cnt == K) res = v[j+1];
        }
            
    }
    if(cnt < K) cout << -1;
    else cout << res;

    return 0;
}