// 20.01.11
// https://www.acmicpc.net/problem/4574
// sudominoku

#include<iostream>
#include<vector>
#include<cstring>
#include<tuple>
using namespace std;
int board[9][9];
int row_ok[10][10];
int col_ok[10][10];
int box_ok[10][10];
int domino_ok[10][10];
int dx[2] = {0, 1};
int dy[2] = {1, 0};

pair<int, int> convert(string s) {
    return make_pair(s[0]-'A', s[1]-'1');
}

bool is_in_range(int row, int col) {
    if (row>=0 && row<9 && col>=0 && col<9) return true;
    else return false;
}

void mark_s(int n, int row, int col, int flag) {
    if(flag>0) board[row][col] = n;
    else board[row][col] = 0;
    row_ok[row][n] = flag;
    col_ok[col][n] = flag;
    box_ok[(row/3)*3 + (col/3)][n] = flag;
}

bool check_s(int n, int row, int col) {
    int r = row_ok[row][n];
    int c = col_ok[col][n];
    int b = box_ok[(row/3)*3 + (col/3)][n];
    if (r+c+b == 0) return true;
    else return false;
}

void mark_d(int n, int m, int flag) {
    domino_ok[n][m] = domino_ok[m][n] = flag;
}

bool check_d(int n, int m) {
    if (domino_ok[n][m] == 0) return true;
    else return false;
}

bool solve(int n) {
    if (n == 81) {
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                cout << board[i][j];
            }
            cout<<'\n';
        }
        return true;
    }
    int row = n/9;
    int col = n%9;
    if (board[row][col] != 0) {
        bool found = solve(n+1);
        return found;
    }
    for (int i=1; i<=9; i++) {
        bool ok_i = check_s(i, row, col);
        if (ok_i) {
            mark_s(i, row, col, 1);
            for (int j=1; j<=9; j++) {
                if (i==j) continue;
                if (check_d(i, j)) {
                    for (int d=0; d<2; d++){
                        int drow = row + dx[d];
                        int dcol = col + dy[d];
                        if (is_in_range(drow, dcol)) {
                            if (board[drow][dcol] == 0 && check_s(j, drow, dcol)) {
                                mark_s(j, drow, dcol, 1);
                                mark_d(i, j, 1);
                                bool found = solve(n+1);
                                if (found) return true;
                                mark_s(j, drow, dcol, 0);
                                mark_d(i, j, 0);
                            } else continue;
                        } else continue;
                    }
                } else continue;
            }
        } else continue;
        mark_s(i,row,col,0);
    }
    return false;
}

int main() {
    for (int t=1;;t++) {
        int N; cin>>N;
        if (N==0) return 0;
        memset(board, 0, sizeof(board));
        memset(row_ok, 0, sizeof(row_ok));
        memset(col_ok, 0, sizeof(col_ok));
        memset(box_ok, 0, sizeof(box_ok));
        memset(domino_ok, 0, sizeof(domino_ok));
        for (int i=0; i<N; i++) {
            int n1, n2; string s1, s2;
            cin >> n1 >> s1 >> n2 >> s2;
            int x1, y1, x2, y2;
            tie(x1,y1) = convert(s1);
            tie(x2,y2) = convert(s2);
            mark_s(n1, x1, y1, 1);
            mark_s(n2, x2, y2, 1);
            mark_d(n1, n2, 1);
        }
        for (int i=1; i<=9; i++) {
            string s; cin>>s;
            int x, y;
            tie(x, y) = convert(s);
            mark_s(i, x, y, 1);
        }
        cout<<"Puzzle "<<t<<'\n';
        solve(0);
    }
}
