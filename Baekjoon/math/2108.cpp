// 백준 2108번 = 통계학

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, sum;
vector<int> v_cnt, v;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    v_cnt.resize(8001);
    v.resize(N);

    for(int i = 0; i < N; ++i) {
        cin >> v[i];
        sum += v[i];
        v_cnt[v[i]+4000]++;
    }

    sort(v.begin(), v.end());

    int max_cnt = 0, freq;

    for(int i = 0; i < 8001; ++i) {
        if(v_cnt[i] > max_cnt) {
            max_cnt = v_cnt[i];
            freq = i;
        }
    }
    
    for(int i = freq + 1; i < 8001; ++i) {
        if(v_cnt[i] == max_cnt) {
            freq = i;
            break;
        }
    }

    int avg = round((double)sum/N);
    
    cout << avg << '\n';
    cout << v[N/2] << '\n';
    cout << freq - 4000 << '\n';
    cout << v[N-1] - v[0] << '\n';

}