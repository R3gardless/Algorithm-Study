// 백준 2020번 = 부분 염기서열

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

#define M 100001

using namespace std;

int n, m, K;

string str;
vector<pair<int, int>> hash_map[M];
vector<string> res;

struct cmp_rule
{
    bool operator()(string const &a, string const &b) const {
        if(a.size() == b.size()) {
            return a < b;
        }
        return a.size() < b.size(); 
    }
};

int getKey(char ch) {
    if(ch == 'A') return 1;
    else if(ch == 'G') return 2;
    else if(ch == 'C') return 3;
    else return 4;
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> K;

    cin >> str;

    for(int i = 0; i < str.size(); ++i) {
        int key1 = 0, key2 = 0, p = 1;
        for(int j = i; j < str.size(); ++j) {
            int k = getKey(str[j]);
            string sub_str = str.substr(i, j - i + 1);
            int len = j - i + 1;
            key1 = (key1 + p * k) % M; 
            key2 = (key2 + p * k) % (M - 1);
            p *= 5; p %= M;
            bool flag = true;
            for(int i = 0; i < hash_map[key1].size(); ++i) {
                if(hash_map[key1][i].first == key2) {
                    hash_map[key1][i].second++;
                    if(hash_map[key1][i].second == m) res.push_back(sub_str);
                    flag = false;
                }
            }
            if(flag) {
                // cout << sub_str << '\n';
                if(m == 1) res.push_back(sub_str);
                hash_map[key1].push_back({key2, 1});
            }
        }
    }
    long long sum = 0;
    for(int i = 0; i< M; ++i) {
        sum += hash_map[i].size();
    }
    cout << sum << '\n';
    sort(res.begin(), res.end(), cmp_rule());
    // for(auto val : res) cout << val << ' ';

    sum = 0;
    for(int i = 0; i < res.size(); ++i) {
        sum += res[i].size();
    }

    cout << sum << '\n';

    cout << res.size() << '\n' << res[K - 1] << '\n';

    return 0;
}