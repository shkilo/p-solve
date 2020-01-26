// 20.01.17
// https://www.acmicpc.net/problem/11047
// 그리디 알고리즘을 쓰려면 왜 그런지 꼭 증명이 필요하다.
// 하지만 왜 못쓰는지는 반례 하나만 들면 된다.
// 이 문제의 경우 모든 액면가가 서로 배수관계가 성립하기 때문에 그리디 알고리즘으로 풀 수 있다.

#include<iostream>
using namespace std;
int values[10];
int main() {
    int N, K; cin>>N>>K;
    for (int i=0; i<N; i++) {
        cin>>values[i];
    }
    int cnt=0;
    for (int i=N-1; i>=0; i--) {
        int tempcnt = K/values[i];
        if (tempcnt == 0) continue;
        cnt += tempcnt; 
        K = K%values[i];
    }
    cout<<cnt;

}
