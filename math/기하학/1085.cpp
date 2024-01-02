// 1085번 = 직사각형에서 탈출

#include <iostream>
#include <algorithm>

using namespace std;

int x, y, w, h, res;

int main() {
    
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> x >> y >> w >> h;

    res = min({x, y, w-x, h-y});

    cout << res << '\n';

    return 0;

}