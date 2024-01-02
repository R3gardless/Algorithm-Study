// 16478번 = 원의 분할

#include <iostream> 

using namespace std;

int a, b, c;

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> a >> b >> c;

    printf("%.7f\n", (a * c) / (double)b);

    return 0;

}