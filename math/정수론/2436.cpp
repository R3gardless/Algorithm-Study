// 2436번 = 공약수

#include <iostream>
#include <vector>

#define MAX 9876543210

using namespace std;

typedef long long ll;

ll GCD, LCM, tmp;
ll resA, resB, tmpA, tmpB, sum;

ll gcd(ll a, ll b) {
    return b ? gcd(b, (a % b)) : a;
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);
    
    sum = MAX;
    cin >> GCD >> LCM;

    tmp = LCM / GCD;

    for(int i = 1; (i * i) <= tmp; ++i) {
        if(tmp % i == 0) {
            if(gcd(i, (tmp / i)) != 1) continue;
            
            tmpA = i * GCD;
            tmpB = (tmp / i) * GCD;
            
            if((tmpA + tmpB) < sum) {
                resA = tmpA; resB = tmpB;
                sum = tmpA + tmpB;
            }
        }
    }

    cout << resA << " " << resB << '\n';

    return 0;

}