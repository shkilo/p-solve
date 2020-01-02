#include<iostream>
#include<vector>
#include<cstring>
#include<tuple>
using namespace std;
int board[9][9];
int lock[9][9];
int col_check[10][10];
int row_check[10][10];
int box_check[10][10];
int domino_check[10][10];
vector<pair<int, int>> blank;

pair<int,int> convert(string s) {
    return make_pair(s[0]-'A',s[1]-'1');
}

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

int avail(int n, int row, int col) {
    cout<<"avail called: "<<n<< ' '<<row <<' '<<col <<'\n';
    bool ok = true;
    cout<<row_check[row][n]<<'\n';
    cout<<col_check[col][n]<<'\n';
    cout<<box_check[(row/3)*3 + (col/3)][n]<<'\n';
    if (row_check[row][n] == 1) ok=false;
    if (col_check[col][n] == 1) ok=false;
    if (box_check[(row/3)*3 + (col/3)][n] == 1) ok=false;

    int ok_d = 0;
    for (int d=1; d<=4; d++) {
        int drow = dx(row, d);
        int dcol = dy(col, d);
        if(drow >= 0 && dcol >= 0) {
            cout << drow << ' ' << dcol << '\n';
            cout << domino_check[n][board[drow][dcol]] << '\n';
            if (domino_check[n][board[drow][dcol]] == 0) ok=false;
        }
        else continue;
    }

    return ok;
}

int avail_

void track(int n, int row, int col, int flag) {
    cout<<"track called: "<<n<< ' '<<row <<' '<<col <<' '<<flag<<'\n';
    if (flag == 1) {
        board[row][col] = n;
        row_check[row][n] = 1;
        col_check[col][n] = 1;
        box_check[(row/3)*3 + (col/3)][n] = 1;
        for (int d=1; d<=4; d++) {
            int drow = dx(row, d);
            int dcol = dy(col, d);
            if (drow >= 0 && dcol >= 0){
                domino_check[n][ board[drow][dcol] ] ++;
                domino_check[ board[drow][dcol] ][n] ++;
            }
            else continue;
        }
    }
    else if (flag == 0){
        board[row][col] = 0;
        row_check[row][n] = 0;
        col_check[col][n] = 0;
        box_check[(row/3)*3 + (col/3)][n] = 0;
        for (int d=1; d<=4; d++) {
            int drow = dx(row, d);
            int dcol = dy(col, d);
            if (drow >= 0 && dcol >= 0){
                domino_check[n][ board[drow][dcol] ] --;
                domino_check[ board[drow][dcol] ][n] --;
            }
            else continue;
        }
    }
    else return;
}

bool solve(int n) {
    cout<<"solve called: "<<n<<'\n';
    if (n==blank.size()) return true;
    int row = blank[n].first;
    int col = blank[n].second;
    for (int i=1; i<=9; i++) {
        if (avail(i, row, col)){
            for (int d=1; d<=4; d++) {
                if ()
            }
            track(i, row, col, 1);
            bool found = solve(n+1);
            if (found) return true;
            track(i, row, col, 0);
        }
        else continue;
    }
    return false;
}

int main() {
    int N; cin>>N;
    if (N==0) return 0;
    for (int i=0; i<N; i++) {
        int n1, n2;
        string s1, s2;
        cin >> n1 >> s1 >> n2 >> s2;
        int x1, y1, x2, y2;
        tie(x1, y1) = convert(s1);
        tie(x2, y2) = convert(s2);
        board[x1][y1] = n1;
        board[x2][y2] = n2;
        row_check[x1][n1] = 1;
        row_check[x2][n2] = 1;
        col_check[y1][n1] = 1;
        col_check[y2][n2] = 1;
        box_check[(x1/3)*3 + (y1/3)][n1] = 1;
        box_check[(x2/3)*3 + (y2/3)][n2] = 1;
        domino_check[n1][n2] = domino_check[n2][n1] = 1;
    }
    for (int i=1; i<=9; i++) {
        string s;
        cin>>s;
        int x,y;
        tie(x,y) = convert(s);
        board[x][y] = i;
        row_check[x][i] = 1;
        col_check[y][i] = 1;
        box_check[(x/3)*3 + (y/3)][i] = 1;
        domino_check[x][y] = domino_check[y][x] = 1;
    }
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            if(board[i][j] == 0) blank.push_back(make_pair(i, j));
        }
    }
    solve(0);
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            cout<< board[i][j];
        }
        cout<<'\n';
    }

}
