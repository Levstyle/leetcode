#include<bits/stdc++.h>

using namespace std;
static auto x = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        const int maxn = nums.size() + 1;
        if(maxn == 1) return 0;
        int p[maxn] = {};
        for(int i = 0; i < maxn-1; ++i){
            p[i + 1] = p[i] + nums[i];
        }

        int low = 1, high = maxn-1;
        if(p[maxn-1] < s) return 0;
        int ret = maxn - 1;
        while(low <= high){
            int mid = ((low + high)>>1);
            if(is_match(s, p, mid, maxn)) {
                ret = mid;
                high = mid-1;
            }else low = mid + 1;
        }

        return ret;
    }

    bool is_match(int s, int p[], int length, int maxn){
        for(int i = 0; i + length < maxn; ++i){
            if(p[i+length] - p[i] >= s) return true;
        }
        return false;
    }
};

int main() {

    return 0;
}
