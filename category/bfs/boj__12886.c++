// 20.01.16
// https://www.acmicpc.net/problem/12886
// dfs, bfs 둘다 해결할 수 있다.
// a, b, c 셋 다 저장하면 메모리가 매우 커진다. a+b는 항상 똑같다는 특성을 이용해 a,b 만 저장한다.

#include<iostream>
using namespace std;
bool flag[2000][2000];

bool dfs(int a, int b, int sum) {
    int c = sum-(a+b);
    if (a==b && b==c) return true;
    if (flag[a][b] == true) return false;
    else {
        flag[a][b] = true;
        flag[b][a] = true;
    }
    bool ab = false, ac = false, bc = false;
    if (a>b) ab = dfs(a-b, b+b, sum);
    if (a<b) ab = dfs(a+a, b-a, sum);
    if (a>c) ac = dfs(a-c, b, sum);
    if (a<c) ac = dfs(a+a, b, sum);
    if (b>c) bc = dfs(a, b-c, sum);
    if (b<c) bc = dfs(a, b+b, sum);
    return ab || ac || bc;
}

int main() {
    int a, b, c; cin>>a>>b>>c;
    cout<<dfs(a, b, a+b+c);
}
