// 19.12.31
// https://www.acmicpc.net/problem/16197
// 문제에 조건에 맞춰 네방향으로 갈라지는 재귀함수.
// 61단 min = 10 으로 하면 10인 답을 포함 못하므로 틀림.

#include<iostream>
#include<vector>
using namespace std;
int N, M;
vector<vector<int>> board;
int go(int i1, int j1, int i2, int j2, int cnt, int d) {
    if (cnt > 10)   return -1;
    if (d == 1) {
        if      (i1 < 0 && i2 < 0)  return -1;
        else if (i1 < 0 || i2 < 0)  return cnt;
        else {
            if (board[i1][j1] == 1 && board[i2][j2] == 1) return -1;
            if (board[i1][j1] == 1) i1++;
            if (board[i2][j2] == 1) i2++;
        }
    }
    if (d == 2) {
        if      (i1 >= N && i2 >= N)  return -1;
        else if (i1 >= N || i2 >= N)  return cnt;
        else {
            if (board[i1][j1] == 1 && board[i2][j2] == 1) return -1;
            if (board[i1][j1] == 1) i1--;
            if (board[i2][j2] == 1) i2--;
        }
    }
    if (d == 3) {
        if      (j1 < 0 && j2 < 0)  return -1;
        else if (j1 < 0 || j2 < 0)  return cnt;
        else {
            if (board[i1][j1] == 1 && board[i2][j2] == 1) return -1;
            if (board[i1][j1] == 1) j1++;
            if (board[i2][j2] == 1) j2++;
        }
    }
    if (d == 4) {
        if      (j1 >= M && j2 >= M)  return -1;
        else if (j1 >= M || j2 >= M)  return cnt;
        else {
            if (board[i1][j1] == 1 && board[i2][j2] == 1) return -1;
            if (board[i1][j1] == 1) j1--;
            if (board[i2][j2] == 1) j2--;
        }
    }

    vector<int> result;
    // up
    result.push_back(go(i1-1, j1, i2-1, j2, cnt+1, 1));
    // down
    result.push_back(go(i1+1, j1, i2+1, j2, cnt+1, 2));
    // left
    result.push_back(go(i1, j1-1, i2, j2-1, cnt+1, 3));
    // right
    result.push_back(go(i1, j1+1, i2, j2+1, cnt+1, 4));

    // min = 10 이 아닌 것에 주의
    int min = 11;
    bool ok = false;
    for (auto i : result) {
        if (i>0 && i<min) {
            min = i;
            ok = true;
        }
    }
    if (ok) return min;
    else return -1;

}

int main() {
    cin>>N>>M;
    board = vector<vector<int>>(N, vector<int>(M, 0));
    // 빈칸(.) : 0
    // 벽(#) : 1
    // 돌(o) : 2
    vector<int> stones;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            char temp; cin>>temp;
            if (temp == '.')    continue;
            if (temp == '#')    board[i][j] = 1;
            if (temp == 'o')    {board[i][j] = 2; stones.push_back(i); stones.push_back(j);}
        }
    }
    int result = go(stones[0], stones[1], stones[2], stones[3], 0, 0);
    cout<<result;

}
