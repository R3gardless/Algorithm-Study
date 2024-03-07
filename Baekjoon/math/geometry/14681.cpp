// 14681번 = 사분면 고르기

#include <iostream>

using namespace std;

int y, x, res;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> x >> y;

    if(x > 0) {
        res = y > 0 ? 1 : 4;
    } else {
        res = y > 0 ? 2 : 3;
    }

    cout << res << '\n';

    return 0;

}