// 20.01.02
// https://www.acmicpc.net/problem/9663
// Backtracking
// 열 방향, 좌우 대각선 방향 제한조건 여부를 메모리에 저장 -> DFS의 각 호출에서 O(1) 가능.

#include<iostream>
#include<vector>
using namespace std;
int N, result;
vector<int> col_check;
vector<int> diag_lr;
vector<int> diag_rl;

void n_queen(int row) {
    if (row == N) {
        result ++;
        return;
    }
    for (int col=0; col<N; col++) {
        if (col_check[col] + diag_lr[row+col] + diag_rl[row-col+(N-1)] == 0) {
            col_check[col] = 1;
            diag_lr[row+col] = 1;
            diag_rl[row-col+(N-1)] = 1;
            n_queen(row+1);
            col_check[col] = 0;
            diag_lr[row+col] = 0;
            diag_rl[row-col+(N-1)] = 0;
        }
        else continue;
    }
}

int main() {
    cin>>N;
    col_check = vector<int>(N);
    diag_lr = vector<int>(2*N-1);
    diag_rl = vector<int>(2*N-1);
    result = 0;
    n_queen(0);
    cout << result;

}
