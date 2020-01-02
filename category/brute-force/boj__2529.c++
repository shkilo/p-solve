// 19.12.30
// https://www.acmicpc.net/problem/14888
// 이런 류의 문제를 처음 풀어봐서 처음에 손을 못댔다. 백준 강의 해설을 빠르게 보고 다시 구현해봄.
// 모든 조합을 다 해볼 필요 없음. ex) k=4일 때 {0, 1, 2, 3, 4}, {9, 8, 7, 6, 5}만 가지고 permutation을 돌리면 된다.
// next_permutation 은 작은 순서, prev_permutation은 큰 순서로 진행되기 때문에 조건을 만족시키면 바로 정답이다.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(vector<int> &num, vector<char> &a) {
    for (int i=0; i<a.size(); i++) {
        if (a[i] == '<' && num[i] > num[i+1])   return false;
        if (a[i] == '>' && num[i] < num[i+1])   return false;
    }
    return true;
}

int main() {
    int k; cin >> k;
    vector<char> a(k);
    vector<int> smalls(k+1);
    vector<int> biggie(k+1);
    for (int i=0; i<k; i++) {
        char temp; cin>>temp;
        a[i] = temp;
    }
    for (int i=0; i<k+1; i++) {
        smalls[i] = i;
        biggie[i] = 9-i;
    }

    do {
        if (compare(smalls, a))
            break;
    } while (next_permutation(smalls.begin(), smalls.end()));
    do {
        if (compare(biggie, a))
            break;
    } while (prev_permutation(biggie.begin(), biggie.end()));

    for (int i=0; i<k+1; i++) {
        cout<<biggie[i];
    }
    cout<<'\n';
    for (int i=0; i<k+1; i++) {
        cout<<smalls[i];
    }
}
