// 20.01.02
// https://www.acmicpc.net/problem/2580
// 행, 열, 박스 체크 위한 메모리 만들어 백트래킹.

#include<iostream>
#include<vector>
using namespace std;
vector<pair<int, int>> blank;
vector<vector<int>> board(9, vector<int>(9));
vector<vector<int>> row_check(9, vector<int>(9));
vector<vector<int>> col_check(9, vector<int>(9));
vector<vector<vector<int>>> box_check(3, vector<vector<int>>(3, vector<int>(9)));

bool check(int n, int row, int col) {
    bool avail = true;
    if (row_check[row][n] == 1) avail = false;
    if (col_check[col][n] == 1) avail = false;
    if (box_check[row/3][col/3][n] == 1) avail = false;
    return avail;
}

void on(int n, int row, int col) {
    board[row][col] = n;
    row_check[row][n] = 1;
    col_check[col][n] = 1;
    box_check[row/3][col/3][n] = 1;
}

void off(int n, int row, int col) {
    board[row][col] = 0;
    row_check[row][n] = 0;
    col_check[col][n] = 0;
    box_check[row/3][col/3][n] = 0;
}

bool go(int n) {
    if (n==blank.size()) return true;
    int row = blank[n].first;
    int col = blank[n].second;
    for(int i=1; i<=9; i++){
        if (check(i, row, col)) {
            on(i, row, col);
            bool ok = go(n+1);
            if (ok) return true;
            off(i, row, col);
        }
        else continue;
    }
    return false;
}

int main() {
    for (int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            int temp; cin >> temp;
            if (temp > 0) {
                board[i][j] = temp;
                row_check[i][temp] = 1;
                col_check[j][temp] = 1;
                box_check[i/3][j/3][temp] = 1;
            }
            else
                blank.push_back(make_pair(i, j));
        }
    }
    go(0);
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            cout<<board[i][j]<<' ';
        }
        cout<<'\n';
    }
}
