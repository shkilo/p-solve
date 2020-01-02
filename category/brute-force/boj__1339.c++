#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stdlib.h>
using namespace std;


int main() {
    int N; cin>>N;
    vector<string> words(N);
    vector<char> chars;
    for (int i=0; i<N; i++) {
        string temp; cin>>temp;
        words[i] = temp;
    }
    chars.push_back(words[0][0]);
    for (int i=0; i<N; i++) {
        for (int j=0; j<words[i].size(); j++) {
            bool isNew = true;
            for (int k=0; k<chars.size(); k++) {
                if (words[i][j] == chars[k]) {
                    isNew = false;
                    break;
                }
            }
            if (isNew) chars.push_back(words[i][j]);
        }
    }
    vector<int> nums(chars.size());
    int start = 10-chars.size();
    for(int i=0; i<chars.size(); i++) {
        nums[i] = start + i;
    }

    vector<string> words_copy = words;
    int max = 0;
    do {
        int total=0;
        for (int c=0; c<chars.size(); c++) {
            for (int i=0; i<N; i++) {
                for (int j=0; j<words[i].size(); j++) {
                    if (words[i][j] == chars[c]) {
                        words_copy[i][j] = '0' + nums[c];
                    }
                }
            }
        }
        for (int i=0; i<N; i++) {
            int temp = atoi(words_copy[i].c_str()); 
            total += temp;
        }
        if (max < total) max = total;
    } while (next_permutation(nums.begin(), nums.end()));
    cout << max;
}
