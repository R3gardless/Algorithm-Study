#include <iostream>
#include <vector>

using namespace std;

void print(vector<double> v) {
    // for(auto val: v) printf("%d ", val);
    // printf("\n");

    vector<double>::iterator it;
    for(it = v.begin(); it != v.end(); ++it) {
        cout << *it << ' ';
    }
    cout << '\n';
}

int main() {
    vector<double> v;

    v.push_back(0.1);
    v.push_back(0.2);
    v.push_back(0.3);
    v[2] = 0.4;
    print(v); // 0.1 0.2 0.4

    v.insert(v.begin() + 2, 0.8);
    print(v); // 0.1 0.2 0.8 0.4

    v.erase(v.begin() + 1);
    print(v); // 0.1 0.8 0.4

    v.push_back(0.9);
    print(v); // 0.1 0.8 0.4 0.9

    vector<double>::iterator it = v.begin();
    *it = 3; // v[0] = 3
    it++; // idx 1 뒤로 이동
    (*it)++; // v[1] += 1
    
    print(v);

    return 0;
}