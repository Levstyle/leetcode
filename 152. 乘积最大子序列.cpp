#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ret = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] < nums[i] * nums[i-1]){
                nums[i] = nums[i] * nums[i-1];
            }
            ret = max(ret, nums[i]);
        }
        return ret;
    }
};
int main() {

    return 0;
}
