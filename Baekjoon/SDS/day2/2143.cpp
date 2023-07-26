// 2143번 = 두 배열의 합

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, N, M;
vector<int> vec_temp;
vector<long long> vec_a;
vector<long long> vec_b;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> T >> N;
    vec_temp.resize(N);
    for(int i = 0; i < N; ++i) cin >> vec_temp[i];
    
    for(int i = 0; i < N; ++i) {
        int sum = 0;
        for(int j = i; j < N; ++j) {
            sum += vec_temp[j];
            vec_a.push_back(sum);
        }
    }

    cin >> M;

    for(int i = 0; i < M; ++i) cin >> vec_temp[i];
    
    for(int i = 0; i < M; ++i) {
        int sum = 0;
        for(int j = i; j < M; ++j) {
            sum += vec_temp[j];
            vec_b.push_back(sum);
        }
    }

    sort(vec_a.begin(), vec_a.end());
    sort(vec_b.rbegin(), vec_b.rend());

    long long currentA, currentB, sum = 0;
    int ptrA = 0, ptrB = 0, res = 0;
    int vecA_size = vec_a.size(), vecB_size = vec_b.size();
    while(true) {
        if(ptrA >= vecA_size || ptrB >= vecB_size) break;
        sum = vec_a[ptrA] + vec_b[ptrB];
        if(sum == T) {
            int countA = 0, countB = 0; 
            currentA = vec_a[ptrA]; currentB = vec_b[ptrB];

            while(ptrA < vecA_size && vec_a[ptrA] == currentA) {
                ptrA++; countA++;
            }
            while(ptrB < vecB_size && vec_b[ptrB] == currentB) {
                ptrB++; countB++;
            }
            res += countA * countB;
        } else if(sum > T) {
            ptrB++;
        } else {
            ptrA++;
        }

    }

    printf("%d\n", res);

    return 0;

}