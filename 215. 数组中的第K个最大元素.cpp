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
    int part(int a, int b, vector<int> &nums){
        int low = a;
        for(int i = a; i < b; ++i){
            if(nums[i] < nums[b]){
                swap(nums[low++], nums[i]);
            }
        }
        swap(nums[low], nums[b]);
        return low;
    }

    int _findKthLargest(vector<int>& nums, int k, int a, int b){
        int _k = part(a, b, nums);
        if(_k == k) return nums[_k];
        else if(_k < k) return _findKthLargest(nums, k, _k + 1, b);
        else return _findKthLargest(nums, k, a, _k - 1);
    }

    int findKthLargest(vector<int>& nums, int k) {
        int _k = nums.size() - k;
        return _findKthLargest(nums, _k, 0, nums.size()-1);
    }
};

int main() {

    return 0;
}
