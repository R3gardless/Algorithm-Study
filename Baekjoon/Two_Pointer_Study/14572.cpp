// 14572번 = 스터디 그룹

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

struct Student {
    int s;
    bool arr[31];

    Student(int s1, bool arr1[31]) : s(s1) {
        for(int i = 0; i < 31; ++i) {
            arr[i] = arr1[i];
        }
    };
    Student() : s(0) {
        for(int i = 0; i < 31; ++i) {
            arr[i] = false;
        }
    };
};

bool compare(const Student & s1,const Student & s2) {
    return s1.s < s2.s;
}

int N, K, D;
int M, algo, d;
ll res, cnt1, cnt2, s, e, diff;
bool arr[31];
Student arrStudent[100000];
vector<int> vecInfo;

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K >> D;

    vecInfo.resize(K + 1);

    for(int i = 0; i < N; ++i) {
        cin >> M >> d;
        fill(arr, arr + 31, false);
        for(int j = 0; j < M; ++j) {
            cin >> algo;
            arr[algo] = true;
        }
        arrStudent[i] = Student(d, arr);
    }

    sort(arrStudent, arrStudent + N, compare); // 투 포인터 전략을 위한 정렬

    s = 0; e = 0;
    for(int i = 1; i <= K; ++i) {
        if(arrStudent[0].arr[i]) vecInfo[i]++;
    }
    while(s <= e) { // D 를 기준으로 투 포인터 전략 사용
        diff = arrStudent[e].s - arrStudent[s].s;
        if(e == N || diff > D) {
            for(int i = 1; i <= K; ++i) {
                if(arrStudent[s].arr[i]) vecInfo[i]--;
            }
            s++;
        } else if(diff <= D) {
            cnt1 = 0; cnt2 = 0;
            for(int i = 1; i <= K; ++i) {
                if(vecInfo[i]) cnt1++;
                if(vecInfo[i] == (e - s + 1)) cnt2++;
            }
            res = max(res, (cnt1 - cnt2) * (e - s + 1));
            e++;
            if(e != N) {
                for(int i = 1; i <= K; ++i) {
                    if(arrStudent[e].arr[i]) vecInfo[i]++;
                }
            }
        }
    }

    cout << res << '\n';

    return 0;
}