// 20.01.16
// https://www.acmicpc.net/problem/14502
// 문제의 조건을 완벽하게 파악하지 못해서 시간 날림

#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
int N, M;
int map[8][8];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool visited[8][8];

int bfs() {
    int cnt = 0;
    queue<pair<int,int>> q;
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            if (map[i][j] == 2) {
                q.push(make_pair(i, j));
                visited[i][j] = true;
            }
        }
    }
    while (!q.empty()) {
        pair<int, int> poped = q.front(); q.pop();
        int x = poped.first;
        int y = poped.second;
        for (int d=0; d<4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx>=0 && nx<N && ny>=0 && ny<M) {
                if (map[nx][ny] == 1 || map[nx][ny] == 2) continue;
                if (visited[nx][ny] == true) continue;
                q.push(make_pair(nx, ny));
                visited[nx][ny] = true; cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    cin>>N>>M;
    int safe = 0;
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            int temp; cin>>temp;
            map[i][j] = temp;
            if (temp == 0) safe++;
        }
    }
    int max = 0;
    for (int i=0; i<N*M-2; i++){
        if (map[i/M][i%M] == 0) {
            map[i/M][i%M] = 1;
            for (int j=i+1; j<N*M-1; j++){
                if(map[j/M][j%M] == 0) {
                    map[j/M][j%M] = 1;
                    for (int k=j+1; k<N*M; k++){
                        if(map[k/M][k%M]==0){
                            map[k/M][k%M]=1;
                            int final_safe = safe - bfs();
                            if (final_safe > max) max = final_safe;
                            map[k/M][k%M] = 0;
                            memset(visited, 0, sizeof(visited));
                        }
                    }
                    map[j/M][j%M] = 0;
                }
            }
            map[i/M][i%M] = 0;
        }
    }
    cout<<max-3;
}
