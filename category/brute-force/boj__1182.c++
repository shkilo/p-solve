// 19.12.31
// https://www.acmicpc.net/problem/1182
// global에 vector<int>(N) 처럼 하면 안된다(N이 null일 때?).
// 간단한 재귀함수

#include<iostream>
#include<vector>
using namespace std;
int N, S;
vector<int> nums;
int result = 0;

void go(int i, int sum, int cnt) {
    if (i==nums.size()) {
        if (sum == S && cnt>0) {
            result++;
            return;
        }
        return;
    }
    go(i+1, sum, cnt);
    go(i+1, sum + nums[i], cnt+1);
}

int main() {
    cin >> N >> S;
    nums = vector<int>(N);
    for (int i=0; i<N; i++) {
        int temp; cin>>temp;
        nums[i] = temp;
    }
    go(0, 0, 0);
    cout<<result;
}
