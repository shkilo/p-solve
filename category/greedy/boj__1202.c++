// 20.01.23
// https://www.acmicpc.net/problem/1202
// 보석의 v 기준으로 정렬한 후 넣을수있는 가장 작은 가방에 넣는다.
// 가방에 보석을 하나만 넣을 수 있어서 greedy가 가능하다.
// 가방을 그냥 vector로 저장하면 O(NK), NK=90,000,000,000 이기 때문에 시간안에 해결 불가능.
// std::set은 balanced bst 형태로 원소를 저장한다. 가방을 multiset(key값의 중복이 가능한 set)으로 저장하면 NlogK로 해결할 수 있다.
// lower_bound(key)는 key값 보다 작거나 같은 가장 큰 원소(int)를 반환한다.
// set.lower_bound는 그 원소의 iterator를 반환한다.
// set.end()는 말 그대로의 end가 아니다.
//
// 다른 방법으로 jew와 bag를 합쳐 무게 기준으로 정렬한 후 jew의 v를 heap에 저장하는 방법이 있다.

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
vector<pair<int,int>> jew;
multiset<int> bag;

bool comp(pair<int,int> &a, pair<int,int> &b) {
    return a.second > b.second;
}

int main() {
    int N, K; cin>>N>>K;
    for (int i=0; i<N; i++) {
        int m, v; cin>>m>>v;
        jew.push_back(make_pair(m, v));
    }
    for (int i=0; i<K; i++) {
        int temp; cin>>temp; bag.insert(temp);
    }

    sort(jew.begin(), jew.end(), comp);
    long long result = 0;
    for (int i=0; i<N; i++) {
        int w = jew[i].first;
        int v = jew[i].second;
        auto it = bag.lower_bound(w);
        if (it != bag.end()) {
            result += v;
            bag.erase(it);
        }
    }
    cout<<result;

}
