//  19.12.30
// https://www.acmicpc.net/problem/14888
// + - * / 각 0 1 2 3 으로 저장 후 순열 돌림.
// minmax_element 함수는 <min, max> 순서로 포인터를 반환한다.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int cal(const vector<int> &n, const vector<int> &o) {
    int result = n[0];
    for (int i=0; i<o.size(); i++) {
        if (o[i] == 0)  result += n[i+1];
        if (o[i] == 1)  result -= n[i+1];
        if (o[i] == 2)  result *= n[i+1];
        if (o[i] == 3)  result /= n[i+1];
    }
    return result;
}

int main(){
    int N; cin>>N;
    vector<int> nums(N);
    vector<int> oper;
    vector<int> result;
    for (int i=0; i<N; i++) {
        int temp; cin>>temp;
        nums[i] = temp;
    }
    for (int i=0; i<4; i++) {
        int temp; cin>>temp;
        for (int j=0; j<temp; j++)
            oper.push_back(i);
    }
    do {
        int temp = cal(nums, oper);
        result.push_back(temp);
    } while (next_permutation(oper.begin(), oper.end()));

    auto ans = minmax_element(result.begin(), result.end());
    cout<<*ans.second<<'\n';
    cout<<*ans.first<<'\n';
}
