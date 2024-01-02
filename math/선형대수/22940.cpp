// 22940번 = 선형 연립 방정식

#include <iostream>

using namespace std;
typedef long long ll;

int N;

double mat[6][7], matX[6], pivot, tmp;

void printMatrix() {
    cout << '\n';
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N + 1; ++j) {
            cout << mat[i][j] << " ";
        }
        cout << '\n';
    }
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N + 1; ++j) cin >> mat[i][j];
    }
    // 시작이 0 으로 시작하는 경우 고려하여 행 switch 필요
    for(int i = 0; i < N; ++i) { 
        for(int j = i; j < N; ++j) {
            if(mat[j][i]) { // pivot 될 행 탐색
                if(i != j) { // pivot 될 행을 i 번째 행과 바꿈
                    for(int k = 0; k < N + 1; ++k) {
                        swap(mat[i][k], mat[j][k]);
                    }
                }
                break;
            }
        }
        // i 번째 행인 pivot 행만 존재
        pivot = mat[i][i];
        for(int j = i + 1; j < N; ++j) {
            if (!mat[j][i]) continue; // 0 인 경우는 계산할 필요 X
            tmp = mat[j][i];
            for(int k = 0; k < N + 1; ++k) mat[j][k] = mat[j][k] * pivot + mat[i][k] * -tmp; 
            // printMatrix();
        }

    }
    // 가우스 소거법 구현
    for(int i = N - 1; i >= 0; --i) {
        tmp = mat[i][N]; // N번째 행 B값 가져오기
        for(int j = N - 1; j > i; --j) {
            tmp -= matX[j] * mat[i][j];
        }
        matX[i] = tmp / mat[i][i];
    }

    for(int i = 0; i < N; ++i) printf("%d ",matX[i]);


    return 0;
}