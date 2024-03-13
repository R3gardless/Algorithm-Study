// 1339번 = 단어 수학

#include <iostream>
#include <string>
#include <cmath>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

int N, len, val;
ll res;
string str;
vector<pair<int, char>> vec;

bool cmp(const pair<int, char> v1, const pair<int, char> v2) {
    if(v1.first > v2.first) return true;
    else return false;
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    for(int i = 0; i < 26; ++i) vec.push_back({0, 'A' + i});

    cin >> N;

    for(int i = 0; i < N; ++i) {
        cin >> str;
        len = str.length() - 1;
        for(int idx = len; idx >= 0; --idx) {        
            vec[str[len - idx] - 'A'].first += pow(10, idx);
        }
    }

    sort(vec.begin(), vec.end(), cmp);

    val = 9;

    for(auto v : vec) {
        res += v.first * val;
        val--;
        if(val < 0) break;
    }

    cout << res << '\n';

    return 0;

}