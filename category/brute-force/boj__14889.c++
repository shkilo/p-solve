// 19.12.30
// https://www.acmicpc.net/problem/14889
// 1팀, 2팀 나누는 것을 {1,1,2,2}, {1,2,1,2} 등의 수열로 생각하면 된다.
// abs() 함수 -> cstdlib

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;

int main() {
    int N; cin>>N;
    vector<vector<int>> s(N, vector<int>(N));
    vector<int> team;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            int temp; cin>>temp;
            s[i][j] = temp;
        }
    }
    for (int i=0; i<N; i++) {
        if (i<N/2)  team.push_back(1);
        else        team.push_back(2);
    }

    int min = 100000;
    do {
        int sum1=0 , sum2=0;
        int diff;
        vector<int> team1;
        vector<int> team2;
        for (int i=0; i<N; i++) {
            if (team[i] == 1)   team1.push_back(i);
            else                team2.push_back(i);
        }
        for (int i=0; i<N/2; i++) {
            for (int j=0; j<N/2; j++) {
                sum1 += s[ team1[i] ][ team1[j] ];
                sum2 += s[ team2[i] ][ team2[j] ];
            }
        }
        diff = abs(sum1 - sum2);
        if (diff < min) min = diff;
    } while(next_permutation(team.begin(), team.end()));

    cout << min;
}
