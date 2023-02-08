// 백준 10840번 = 구간 성분

#include <iostream>
#include <vector>
#include <utility>
#include <string>

#define M 5000011

using namespace std;

int char_map[26];
vector<pair<int, int>> hash_map[M];

string str1, str2;

bool isPrime(int num) {

    for(int i = 2; i * i <= num; ++i) {
        if(num % i == 0) return false;
    }
    return true;
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int idx = 0, res = 0;

    for(int num = 2;; ++num) {
        if(idx >= 26) break;

        if(isPrime(num)) char_map[idx++] = num;
    }

    cin >> str1 >> str2;

    for(int i = 0; i < str1.size(); ++i) {
        int k1 = 1, k2 = 1;
        for(int j = i; j < str1.size(); ++j) {
            int ch = str1[j] - 'a';
            int l = j - i + 1;
            k1 = (k1 * char_map[ch]) % M;
            k2 = (k2 * char_map[ch]) % (M - 1);
            hash_map[k1].push_back({k2, l});
        }
    }

    for(int i = 0; i < str2.size(); ++i) {
        int k1 = 1, k2 = 1;
        for(int j = i; j < str2.size(); ++j) {
            int ch = str2[j] - 'a';
            int l = j - i + 1;
            k1 = (k1 * char_map[ch]) % M;
            k2 = (k2 * char_map[ch]) % (M - 1);
            for(int k = 0; k < hash_map[k1].size(); ++k) {
                if(hash_map[k1][k] == make_pair(k2, l)) res = max(res, l);
            }
         }
    }

    cout << res << '\n';
    
    return 0;
}