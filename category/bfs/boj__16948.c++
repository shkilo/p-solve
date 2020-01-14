// 20.01.14
// https://www.acmicpc.net/problem/16948

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int dx[6] = {-2, -2, 0, 0, 2, 2};
int dy[6] = {-1, 1, -2, 2, -1, 1};
int dist[200][200];

void bfs(pair<int,int> &a, pair<int,int> &b, int size){
    queue<pair<int,int>> q;
    q.push(a);
    while (!q.empty()) {
        pair<int, int> poped = q.front(); q.pop();
        for (int d=0; d<6; d++) {
            int nx = poped.first + dx[d];
            int ny = poped.second + dy[d];
            if (nx == b.first && ny == b.second) {
                cout<< dist[poped.first][poped.second] + 1 << '\n';
                return;
            }
            if (nx>=0 && nx<size && ny>=0 && ny<size && dist[nx][ny]==0) {
                dist[nx][ny] = dist[poped.first][poped.second] + 1;
                q.push(make_pair(nx,ny));
            }
        }
    }
    cout<<-1<<'\n';

}

int main() {
    int N; cin>>N;
    pair<int, int> a, b;
    int ax, ay, bx, by; cin>>ax>>ay>>bx>>by;
    a = make_pair(ax, ay);
    b = make_pair(bx, by);
    dist[ax][ay] = 0;
    bfs(a, b, N);
}
