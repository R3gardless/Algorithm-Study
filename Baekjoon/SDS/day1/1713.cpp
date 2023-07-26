// 1713번 = 후보 추천하기

#include <iostream>
#include <vector>

using namespace std;

int check_recommended[100];
vector<int> vec;

int N, cnt, vote;

int find_victim() {
    int min_val = 1234567890;
    int victim, victim_idx;
    for(int idx = 0; idx < : vec) {
        if(check_recommended[number] <= min_val) {
            min_val = check_recommended[number];
            victim = number;
        }
    }
    vec.erase(victim);

    return victim; 
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> cnt;

    for(int i = 0; i < cnt; ++i) {
        cin >> vote;

        if(check_recommended[vote]) {
            check_recommended[vote]++;
        } else {
            if(vec.size() > N) {
                find_victim()
            } else {
                vec.push_back(vote);
                check_recommended[vote]++;
            }
        }
    }
}