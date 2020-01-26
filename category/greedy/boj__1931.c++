// 20.01.18
// https://www.acmicpc.net/problem/1931
// 증명 : 그리디 알고리즘이 선택한 집합 {i1, i2, i3, ..., in}
//        최적해가 선택한 집합 {j1, j2, j3, ..., jm}
//        ix = jx 일때 jx+1 보다 빠른 ix+1이 있어 선택한다고 해도 최적해의 값이 증가할 수 없다.
// 정렬할 때 끝나는 시간이 같으면 시작하는 시간으로 정렬을 해야 한다. (문제의 조건 때문에)

#include<iostream>
#include<algorithm>
using namespace std;
pair<int,int> info[100000];
bool comp(pair<int,int> &a, pair<int,int> &b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    else return a.second <= b.second;
}
int main() {
    int N; cin>>N;
    for (int i=0; i<N; i++) {
        int s, e; cin>>s>>e;
        info[i] = make_pair(s, e);
    }
    sort(info, info+N, comp);
    bool avail = true;
    int start_value = 0;
    int start_index = 0;
    int cnt = 0;
    // while (avail) {
    //     avail = false;
    //     for (int i=start_index; i<N; i++) {
    //         if (info[i].first >= start_value) {
    //             cnt++;
    //             start_value = info[i].second;
    //             start_index = i;
    //             avail = true;
    //             break;
    //         }
    //     }
    // }
    for (int i=0; i<N; i++) {
        if (info[i].first>=start_value) {
            start_value = info[i].second;
            cnt++;
        }
    }
    cout<<cnt;
}
