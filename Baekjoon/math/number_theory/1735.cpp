// 1735번 = 분수 합

#include <iostream>

using namespace std;

int tmp, lcm, a, b;
int num1, num2, denom1, denom2;
int res_num;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> num1 >> denom1 >> num2 >> denom2;

    tmp = gcd(denom1, denom2);

    a = denom1 / tmp; b = denom2 / tmp;

    lcm = a * b * tmp;
    res_num = (b * num1) + (a * num2);

    cout << res_num / gcd(res_num, lcm) << " " << lcm / gcd(res_num, lcm) << '\n';

    return 0;

}