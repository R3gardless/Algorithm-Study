// 2143번 = 두 배열의 합

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int T, N, M;
ll arrA[1000], arrB[1000], sum;
ll curA, curB, cntA, cntB, ptrA, ptrB, res; 
vector<ll> sumA, sumB;

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> T;
    cin >> N;
    
    for(int i = 0; i < N; ++i) cin >> arrA[i];

    for(int i = 0; i < N; ++i) {
        sum = 0;
        for(int j = i; j < N; ++j) {
            sum += arrA[j];
            sumA.push_back(sum);
        }
    }

    cin >> M;

    for(int i = 0; i < M; ++i) cin >> arrB[i];

    for(int i = 0; i < M; ++i) {
        sum = 0;
        for(int j = i; j < M; ++j) {
            sum += arrB[j];
            sumB.push_back(sum);
        }
    }

    sort(sumA.begin(), sumA.end()); // 오름차순
    sort(sumB.rbegin(), sumB.rend()); // 내림차순

    ptrA = 0; ptrB = 0;
    while(ptrA < sumA.size() && ptrB < sumB.size()) {
        sum = sumA[ptrA] + sumB[ptrB];

        if(sum == T) {
            curA = sumA[ptrA]; curB = sumB[ptrB];
            cntA = 0; cntB = 0;

            while(ptrA < sumA.size() && sumA[ptrA] == curA) {
                cntA++;
                ptrA++;
            }
            while(ptrB < sumB.size() && sumB[ptrB] == curB) {
                cntB++;
                ptrB++;
            }
            res += cntA * cntB; // cntA, cntB 를 long long 으로 선언해줘야 하는 이유
        } else if(sum > T) {
            ptrB++;
        } else {
            ptrA++;
        }
    }

    cout << res << '\n';

    return 0;
}