// 20.01.11
// https://www.acmicpc.net/source/share/d86cd86c235546c2a77abe1654213dde

#include<iostream>
#include<vector>
using namespace std;
char board[20][20];
bool alphabet[26];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int solve(int x, int y, int r, int c, int cnt){
    int n = board[x][y] - 'A';
    alphabet[n] = true;
    int max = cnt;
    for (int d=0; d<4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx >= 0 && nx < r && ny >=0 && ny < c) {
            int a = board[nx][ny] - 'A';
            if (alphabet[a]) continue;
            else {
                int temp = solve(nx, ny, r, c, cnt+1);
                if (temp>max) max = temp;
            }
        } else continue;
    }
    alphabet[n] = false;
    return max;
}

int main() {
    int R, C; cin >> R >> C;
    for (int i=0; i<R; i++) {
        string s; cin >> s;
        for (int j=0; j<C; j++) {
            board[i][j] = s[j];
        }
    }
    int ans = solve(0, 0, R, C, 1);
    cout<<ans;
}
