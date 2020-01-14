#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
bool flag[10001];
int parent[10001];
char op[10001];
char opset[4] = {'D', 'S', 'L', 'R'};

void bfs(int from, int to) {
    queue<int> q;
    q.push(from);
    flag[from] = true;
    parent[from] = -1;
    op[from] = 'q';
    while (!q.empty()) {
        int poped = q.front(); q.pop();
        // cout<<"poped: "<<poped<<'\n';
        for (int i=0; i<4; i++) {
            int next;
            if (i==0) {
                next = poped *2;
                if (next > 9999) next = next % 10000;
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
            if (flag[next]==false) {
                q.push(next);
                // cout<<"pushed: "<<next<<'\n';
                flag[next] = true;
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
        memset(parent, 0, sizeof(parent));
        memset(op, 'x', sizeof(op));
        memset(flag, false, sizeof(flag));
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
