// 20.01.22
// https://www.acmicpc.net/problem/1080
// 각 3*3칸은 바꾸거나 바꾸지 않거나 두 경우 뿐이다.
// [0][0] 칸은 바뀔수 있는 경우가 한가지 뿐이므로 순서대로 결정해 나가면 된다.

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

void mark(int x, int y, vector<vector<bool>> &m) {
    for (int i=x; i<x+3; i++) {
        for (int j=y; j<y+3; j++){
            m[i][j] = !m[i][j];
        }
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    vector<vector<int>> base(N, vector<int>(M));
    vector<vector<int>> target(N, vector<int>(M));
    vector<vector<bool>> flag(N, vector<bool>(M));
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            scanf("%1d", &base[i][j]);
        }
    }
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            scanf("%1d", &target[i][j]);
        }
    }
    int cnt = 0;
    for (int i=0; i<N-2; i++) {
        for (int j=0; j<M-2; j++) {
            if (!flag[i][j]) {
                if (base[i][j] != target[i][j]) {
                    mark(i, j, flag);
                    cnt++;
                }
            }
            else {
                if (base[i][j] == target[i][j]) {
                    mark(i, j, flag);
                    cnt++;
                }
            }
        }
    }
    for (int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(!flag[i][j] && base[i][j]!=target[i][j]){
                cout<<-1; return 0;
            }
            else if(flag[i][j] && base[i][j]==target[i][j]){
                cout<<-1; return 0;
            }
        }
    }
    cout<<cnt;
}
