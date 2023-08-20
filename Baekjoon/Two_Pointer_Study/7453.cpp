// 백준 7453번 = 합이 0인 네 정수

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int N;
ll arrA[4000], arrB[4000], arrC[4000], arrD[4000];
ll sizeAB, sizeCD, ptrAB, ptrCD, sum, res;
ll curAB, curCD, cntAB, cntCD;
vector<ll> sumAB, sumCD;

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; ++i) {
        cin >> arrA[i] >> arrB[i] >> arrC[i] >> arrD[i];
    }

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            sumAB.push_back(arrA[i] + arrB[j]);
            sumCD.push_back(arrC[i] + arrD[j]); 
        }
    }

    sort(sumAB.begin(), sumAB.end()); // 오름차순
    sort(sumCD.rbegin(), sumCD.rend()); // 내림차순

    sizeAB = sumAB.size();
    sizeCD = sumCD.size();
    
    while(ptrAB < sizeAB && ptrCD < sizeCD) {
        sum = sumAB[ptrAB] + sumCD[ptrCD];

        if(sum == 0) {
            curAB = sumAB[ptrAB]; curCD = sumCD[ptrCD];
            cntAB = 0; cntCD = 0;

            while(ptrAB < sizeAB && sumAB[ptrAB] == curAB) {
                ptrAB++;
                cntAB++;
            }
            
            while(ptrCD < sizeCD && sumCD[ptrCD] == curCD) {
                ptrCD++;
                cntCD++;
            }
            
            res += cntAB * cntCD;

        } else if(sum > 0) {
            ptrCD++;
        } else {
            ptrAB++;
        }
    }

    cout << res << '\n';

    return 0;

}