// 2143번 = 두 배열의 합

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int T, N, M;
vector<int> vec_temp;
vector<ll> vec_a, vec_b;
ll ptrA, ptrB, curA, curB, cntA, cntB, res, sum;


int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> T >> N;
    vec_temp.resize(N);
    for(int i = 0; i < N; ++i) cin >> vec_temp[i];

    for(int i = 0; i < N; ++i) {
        sum = 0;
        for(int j = i; j < N; ++j) {
            sum += vec_temp[j];
            vec_a.push_back(sum);
        }
    }

    cin >> M;
    vec_temp.resize(M);
    for(int i = 0; i < M; ++i) cin >> vec_temp[i];

    for(int i = 0; i < M; ++i) {
        sum = 0;
        for(int j = i; j < M; ++j) {
            sum += vec_temp[j];
            vec_b.push_back(sum);
        }
    }

    sort(vec_a.begin(), vec_a.end());
    sort(vec_b.rbegin(), vec_b.rend());

    while(ptrA < vec_a.size() && ptrB < vec_b.size()) {
        sum = vec_a[ptrA] + vec_b[ptrB];
        if(sum == T) {
            cntA = 0; cntB = 0; 
            curA = vec_a[ptrA]; curB = vec_b[ptrB];

            while(ptrA < vec_a.size() && vec_a[ptrA] == curA) {
                ptrA++; cntA++;
            }
            while(ptrB < vec_b.size() && vec_b[ptrB] == curB) {
                ptrB++; cntB++;
            }
            res += cntA * cntB;
        } else if(sum > T) {
            ptrB++;
        } else {
            ptrA++;
        }

    }

    printf("%lld\n", res);

    return 0;

}