#include<iostream>
#include<vector>
#include<utility>

using namespace std;

int N;
vector<int> v, g;

void bubbleSort() {
    bool flag = true;
    int j;
    while(flag) {
        flag = false;
        for(j = 1; j < N; ++j) {
            if(v[j] < v[j-1]) {
                swap(v[j], v[j-1]);
                flag = true;
            }
        } 
    }
}

// void bubbleSort() {
//     bool flag = true;
//     int i, j;
//     for(i = 1 ; i < N; ++i) {
//         for(j = i; j < N; ++j) {
//             if(v[j] < v[j-1]) swap(v[j], v[j-1]);
//         }
//     }
// }

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    scanf("%d", &N);

    v.assign(N, 0);
    for(int i = 0; i < N; ++i) scanf("%d", &v[i]);

    bubbleSort();

    for(auto i: v) cout << i << ' ';
    
    return 0;
}