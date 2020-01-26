// 20.01.22
// https://www.acmicpc.net/problem/11399

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int times[1000];
    int N; cin>>N;
    for (int i=0; i<N; i++) {
        cin>>times[i];
    }
    sort(times, times+N);
    int result = 0;
    for (int i = 0; i < N; i++) {
        result += times[i] * (N-i);
    }
    cout<<result;
}
