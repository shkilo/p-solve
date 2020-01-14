// 20.10.14
// https://www.acmicpc.net/problem/9019
// 메모리 초과가 떠서 시간을 엄청 날렸는데 실수 하나 때문이었음
// parent 캐시 말고 visit 캐시를 따로 만들어야 하나 고민했는데 그럴 필요 없었다.

#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
int parent[10001];
char op[10001];
char opset[4] = {'D', 'S', 'L', 'R'};

void bfs(int from, int to) {
    queue<int> q;
    q.push(from);
    parent[from] = -2;
    op[from] = 'q';
    while (!q.empty()) {
        int poped = q.front(); q.pop();
        for (int i=0; i<4; i++) {
            int next;
            if (i==0) {
                next = poped *2;
                if (next > 9999) next = next % 10000;       // %를 /=로 써서 5시간 날려먹음
            }
            if (i==1) {
                if (poped == 0) next = 9999;
                else next = poped-1;
            }
            if (i==2) {
                next = poped/1000 + (poped%1000)*10;
            }
            if (i==3) {
                next = (poped%10)*1000 + (poped/10);
            }
            if (parent[next]==-1) {
                q.push(next);
                parent[next] = poped;
                op[next] = opset[i];
                if (next==to) return;

            }
        }
    }
}

int main(){
    int t; cin>>t;
    while (t--) {
        memset(parent, -1, sizeof(parent));
        memset(op, 'x', sizeof(op));
        int from, to; cin>>from>>to;
        bfs(from, to);
        vector<char> ans;
        while (parent[to]>=0) {
            ans.push_back(op[to]);
            to=parent[to];
        }
        for (int i=ans.size()-1; i>=0; i--) {
            cout<<ans[i];
        }
        cout<<'\n';
    }

}
