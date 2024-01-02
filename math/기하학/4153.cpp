// 4153번 = 직각삼각형

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a, b, c;
vector<int> vec;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    while(1) {
        
        vec.assign(3, 0);
        
        cin >> vec[0] >> vec[1] >> vec[2];
        sort(vec.begin(), vec.end());

        if(!vec[0] && !vec[1] && !vec[2]) break;

        if((vec[2] * vec[2]) == (vec[1] * vec[1]) + (vec[0] * vec[0])) cout << "right\n";
        else cout << "wrong\n";
    }

    return 0;

}