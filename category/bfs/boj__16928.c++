// 20.01.12
// https://www.acmicpc.net/problem/16928

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int board[100+1];
int dist[100+1];

int solve() {
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int poped = q.front(); q.pop();
        if (poped == 100) {
            return dist[poped];
        }
        if (board[poped] > 0) {
            dist[board[poped]] = dist[poped];
            poped = board[poped];
        }
        for (int i=1; i<=6; i++) {
            int next = poped + i;
            if (dist[next] == 0) {
                dist[next] = dist[poped]+1;
                q.push(next);
            }
        }
    }
    return -1;
}

int main() {
    int N, M; cin>>N>>M;
    for (int i=0; i<N; i++) {
        int x, y; cin>>x>>y;
        board[x] = y;
    }
    for (int j=0; j<M; j++) {
        int u, v; cin>>u>>v;
        board[u] = v;
    }
    int ans = solve();
    cout<<ans;
}
