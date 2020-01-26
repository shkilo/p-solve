#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool comp(pair<int,int>& a, pair<int,int>& b) {
    return a.second<b.second;
}
int main() {
    int n; cin>>n;
    if (n==0) {cout<<0;return 0;}
    vector<pair<int,int>> c(n);
    for (int i=0; i<n; i++) {
        cin>>c[i].first>>c[i].second;
    }
    sort(c.begin(), c.end(), comp);
    int ans=0;
    int max=0;
    for (int i=0; i<n-1; i++) {
        if (c[i+1].second == c[i].second) {
            if (c[i].first>max) max=c[i].first;
        }
        else {
            if (c[i].first>max) max=c[i].first;
            ans+=max;
            max=0;
        }
    }
    if (c[n-1].first>max) max=c[n-1].first;
    ans+=max;
    cout<<ans;
}
