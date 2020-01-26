// 20.01.22
// https://www.acmicpc.net/problem/2138

#include <cstdio>
#include <vector>
using namespace std;
int N;
int base[100000];
int target[100000];
bool flag[100000];
bool copy[100000];
int cnt[2];

void swch(int i) {
    flag[i-1] = !flag[i-1];
    flag[i] = !flag[i];
    flag[i+1] = !flag[i+1];
}

void go(int i, int s) {
    if (i == N-1) {
        if (flag[i-1]) {
            if (base[i-1] == target[i-1]) {
                flag[i-1] = !flag[i-1];
                flag[i] = !flag[i];
                cnt[s] ++;
            }
            return;
        }
        else {
            if (base[i-1] != target[i-1]) {
                flag[i-1] = !flag[i-1];
                flag[i] = !flag[i];
                cnt[s] ++;
            }
            return;
        }
    }
    if (flag[i-1]) {
        if (base[i-1] == target[i-1]) {swch(i); cnt[s]++;}
        go(i+1, s);
    }
    else {
        if (base[i-1] != target[i-1]) {swch(i); cnt[s]++;}
        go(i+1, s);
    }
}

int main() {
    scanf("%d\n", &N);
    for (int i=0; i<N; i++) {
        scanf("%1d", &base[i]);
    }
    for (int i=0; i<N; i++) {
        scanf("%1d", &target[i]);
    }
    flag[0] = true;
    flag[1] = true;
    cnt[0] ++;
    go(1, 0);
    for (int i=0; i<N; i++) {
        if (!flag[i] && base[i] != target[i]) {
            cnt[0] = -1; break;
        }
        if (flag[i] && base[i] == target[i]) {
            cnt[0] = -1; break;
        }
    }

    for (int i=0; i<N; i++) flag[i] = false;

    go(1, 1);
    for (int i=0; i<N; i++) {
        if (!flag[i] && base[i] != target[i]) {
            cnt[1] = -1; break;
        }
        if (flag[i] && base[i] == target[i]) {
            cnt[1] = -1; break;
        }
    }

    int result;
    if (cnt[0] == -1 && cnt[1] == -1) printf("%d\n", -1);
    else if (cnt[0] == -1) printf("%d\n", cnt[1]);
    else if (cnt[1] == -1) printf("%d\n", cnt[0]);
    else {
        if (cnt[0]<=cnt[1]) printf("%d\n", cnt[0]);
        else printf("%d\n", cnt[1]);
    }
}
