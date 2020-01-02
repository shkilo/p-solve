// 19.12.31
// https://www.acmicpc.net/problem/16198
// *vector<int> a(b) -> b를 복사

#include<iostream>
#include<vector>
using namespace std;
int N;
vector<int> balls;

int go(vector<int> &v) {
    if (v.size() == 2)  return 0;
    int max = 0;
    for (int i = 1; i<v.size()-1; i++) {
        int total = v[i-1] * v[i+1];
        vector<int> tempv(v);
        tempv.erase(tempv.begin()+i);
        total += go(tempv);
        if (total>max) max = total;
    }
    return max;
}

int main() {
    cin>>N;
    balls = vector<int> (N);
    for (int i=0; i<N; i++) {
        int temp; cin>>temp;
        balls[i] = temp;
    }
    int result = go(balls);
    cout<<result;
}
