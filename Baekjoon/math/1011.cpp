// 1011번 = Fly me to the Alpha Centauri

#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

int T;
ll x, y, res, diff, root;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> T;

    while(T--) {
        res = 0;
        
        cin >> x >> y;

        diff = y - x; // diff 의 제곱근을 계산        

        root = (ll)sqrt(diff);

        res = 2 * root - 1;
        res += ceil((diff - pow(root, 2)) / (double)root);

        cout << res << '\n';
    }


    return 0;
}