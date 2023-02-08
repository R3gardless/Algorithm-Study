#include<iostream>
#include<vector>
#include<utility>
using namespace std;

int N;
vector<int> v;


void selectionSort() {
    int i, j, min_idx;
    for(i = 0; i < N; ++i) {
        min_idx = i;
        for(j = i + 1; j < N; ++j) {
            if(v[min_idx] > v[j]) min_idx = j;
        }
        swap(v[min_idx], v[i]);
    }
}


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    scanf("%d", &N);

    v.assign(N, 0);
    for(int i = 0; i < N; ++i) scanf("%d", &v[i]);

    selectionSort();

    for(auto i: v) cout << i << ' ';
    
    return 0;
}