#include<iostream>
#include<vector>

using namespace std;

int N;
vector<int> v;

void insertionSort() {
    int temp, j;
    for(int i = 1; i < N; ++i) {
        temp = v[i];
        j = i - 1;
        while(j >= 0 && v[j] < temp) {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = temp;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    scanf("%d", &N);

    v.assign(N, 0);
    for(int i = 0; i < N; ++i) scanf("%d", &v[i]);

    insertionSort();

    for(auto i: v) cout << i << ' ';
    
    return 0;
}