#include<bits/stdc++.h>

using namespace std;
static auto x = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int rob(vector<int>& nums) {
        const int maxn = nums.size();
        if(maxn <= 0) return 0;
        int dp[maxn] = {};
        int ret = 0;
        for(int i = 0; i < maxn; ++i){
            dp[i] = nums[i];
            if(i - 2 >= 0){
                dp[i] = max(dp[i], nums[i] + dp[i-2]);
            }
            if(i - 3 >= 0){
                dp[i] = max(dp[i], nums[i] + dp[i-3]);
            }
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};

int main() {

    return 0;
}
