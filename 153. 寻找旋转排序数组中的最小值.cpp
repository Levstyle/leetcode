#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int ret = nums[0], low = 0, high = nums.size()-1;
        while(low <= high){
            int mid = (low + high)>>1;
            if(nums[mid] < nums[high]){
                ret = min(ret, nums[mid]);
                high = mid - 1;
            }else{
                low = mid + 1;
                ret = min(ret, nums[mid]);
            }
        }
        return ret;
    }
};
int main() {

    return 0;
}
