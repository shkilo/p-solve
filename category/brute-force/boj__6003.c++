// 19.12.31
// https://www.acmicpc.net/problem/6603
// 집합 S의 각 원소를 고르면 cnt++, 고르지 않으면 cnt, cnt==6 일 때 출력하는 재귀함수 활용.

#include<iostream>
#include<vector>
using namespace std;

int k;
vector<int> s;
vector<int> ans;

void go(int i, int cnt) {
    if (cnt == 6) {
        for (auto x : ans) {
            cout<<x<<' ';
        }
        cout<<'\n';
        return;
    }
    if (i == s.size()) return;
    ans.push_back(s[i]);
    go(i+1, cnt+1);
    ans.pop_back();
    go(i+1, cnt);
}

int main() {
    while (true) {
        cin >> k;
        if (k == 0) return 0;
        s = vector<int>(k);
        for (int i=0; i<k; i++) {
            int temp; cin>>temp;
            s[i] = temp;
        }
        go(0, 0);
        ans.clear();
        cout<<'\n';
    }
}
