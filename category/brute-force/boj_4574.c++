#include<iostream>
#include<vector>
using namespace std;
int board[9][9];
int col_check[10][10];
int row_check[10][10];
int box_check[10][10];
vector<pair<int>> blank;

int dx(int x, int d) {
    if (x>0 && d==1) return x-1;
    else if (x<8 && d==2) return x+1;
    else if (d==3) return x;
    else if (d==4) return x;
    else return -1;
}

int dy(int y, int d) {
    if (d==1) return y;
    else if (d==2) return y;
    else if (y>0 && d==3) return y-1;
    else if (y<8 && d==4) return y+1;
    else return -1;
}

bool avail(int n, int m, int row1, int col1, int row2, int col2) {
    bool n_ok=true, m_ok=true;
    if (row_check[row1][n] == 1) n_ok=false;
    if (col_check[col1][n] == 1) n_ok=false;
    if (box_check[(row1/3)*3 + (col1/3)][n] == 1) n_ok=false;

    if (row_check[row2][m] == 1) m_ok=false;
    if (col_check[col2][m] == 1) m_ok=false;
    if (box_check[(row2/3)*3 + (col2/3)][m] == 1) m_ok=false;

    if (n_ok && m_ok) return true;
    else return false;
}

void track(int n, int m, int row1, int col1, int row2, int col2, int on_off) {
    if (on_off == 1) {
        board[row1][co1] = n;
        row_check[row1][n] = 1;
        col_check[col1][n] = 1;
        box_check[(row1/3)*3 + (col1/3)][n] = 1;

        board[row2][col2] = m;
        row_check[row2][m] = 1;
        col_check[col2][m] = 1;
        box_check[(row2/3)*3 + (col2/3)][m] = 1;
    }
    else {
        board[row1][co1] = 0;
        row_check[row1][n] = 0;
        col_check[col1][n] = 0;
        box_check[(row1/3)*3 + (col1/3)][n] = 0;

        board[row2][col2] = 0;
        row_check[row2][m] = 0;
        col_check[col2][m] = 0;
        box_check[(row2/3)*3 + (col2/3)][m] = 0;
    }
}

bool go(int n) {
    if (n==blank.size()) return true;
    int row1 = blank[n].first;
    int col1 = blank[n].second;
    for (int i=1; i<=9; i++) {
        for (int j=1; j<=9; j++) {
            if (i==j) continue;
            for (int d=1; d<=4; d++) {
                int row2 = dx[row1, d];
                int col2 = dy[col1, d];
                if (row2 >= 0 && col2 >=0){
                    if (avail(i, j, row1, col1, row2, col2)) {
                        track(i, j, row1, col1, row2, col2, 1);
                        go(n+1);
                        track(i, j, row1, col1, row2, col2, 0);
                    }
                    else continue;
                }
                else continue;
            }
        }
    }
}

int main() {
    int N; cin>>N;

}
