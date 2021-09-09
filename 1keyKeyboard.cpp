#include<iostream>

using namespace std;

class Solution {
public:

    int memo[1000][1000];

    int minSteps(int n) {
        if (n == 1) {return 0;}
        for(int i = 0; i < 1000; i++){for(int j = 0; j < 1000; j++){memo[i][j] = -1;}}
        return 1 + this->solution(1, n, 1);
    }
    
    int solution(int inp_len, int tar_len, int paste_len) {

        if (inp_len == tar_len) {
            return 0;
        }

        if (inp_len > tar_len) {
            return 1000;
        }


        if (memo[inp_len][paste_len] != -1) {
            return memo[inp_len][paste_len];
        }

        int pasteStep, copyAllStep;

        if (inp_len == paste_len) {
            pasteStep = this->solution(inp_len+paste_len, tar_len, paste_len);
            copyAllStep = 1000;
        } else {
            pasteStep = this->solution(inp_len+paste_len, tar_len, paste_len);
            copyAllStep = this->solution(inp_len, tar_len, inp_len);
        }
        
        int ans = 1 + this->min(pasteStep, copyAllStep);
        memo[inp_len][paste_len] = ans;
        return ans;
    }
    
    int min(int a, int b) {
        if (a <= b) {
            return a;
        }
        return b;
    }
};

int main() {
    Solution s = Solution();
    cout << s.minSteps(3) << endl;
    return 0;
}