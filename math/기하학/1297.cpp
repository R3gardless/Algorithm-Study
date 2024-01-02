// 1297번 = TV 크기

#include <iostream>
#include <math.h>

using namespace std;

int D, H, W;
double tmp;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> D >> H >> W;

    tmp = sqrt((D*D) / (double)((H*H) + (W*W)));

    cout << (int)(H * tmp) << " " << (int)(W * tmp) << '\n';

    return 0;

}