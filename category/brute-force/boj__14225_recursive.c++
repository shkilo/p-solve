// 20.01.12
// https://www.acmicpc.net/problem/14225
// 고르는 경우, 안고르는 경우 recursive

#include<iostream>
#include<vector>
using namespace std;
int seq[20];
bool check[20*100000+10];

void go(int idx, int sum, int size) {
    if (idx == size) {check[sum] = true; return;}
    go(idx+1, sum+seq[idx], size);
    go(idx+1, sum, size);
}

int main() {
    int N; cin>>N;
    for (int i=0; i<N; i++) {
        cin>>seq[i];
    }
    go(0, 0, N);
    for (int i=1;;i++) {
        if (check[i]==false) {
            cout<<i;
            return 0;
        }
    }
}
