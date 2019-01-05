#include<bits/stdc++.h>

using namespace std;


static auto x = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}
();

class Solution {
public:

    int _rob(vector<int>& nums) {
        const int maxn = nums.size();
        if(maxn <= 0)
            return 0;
        int dp[maxn] = {};
        int ret = 0;
        for(int i = 0; i < maxn; ++i) {
            dp[i] = nums[i];
            if(i - 2 >= 0) {
                dp[i] = max(dp[i], nums[i] + dp[i-2]);
            }
            if(i - 3 >= 0) {
                dp[i] = max(dp[i], nums[i] + dp[i-3]);
            }
            ret = max(ret, dp[i]);
        }
        return ret;
    }

    int rob(vector<int>& nums) {
        if(nums.size() < 2)
            return nums.size() == 0?0:nums[0];
        int ret = 0;
        vector<int>b;
        for(int i = 1; i < nums.size(); ++i) {
            b.push_back(nums[i]);
        }
        ret = max(ret, _rob(b));
        b.clear();
        for(int i = 0; i + 1 < nums.size(); ++i)
            b.push_back(nums[i]);
        ret = max(ret, _rob(b));

        return ret;
    }
};

int main() {

    return 0;
}
