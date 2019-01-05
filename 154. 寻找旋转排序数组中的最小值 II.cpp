class Solution
{
  public:
    int findMin(vector<int> &nums)
    {
        int mid = 0, low = 0, high = nums.size() - 1;
        while (nums[low] >= nums[high])
        {
            if (low + 1 == high)
                return nums[high];
            mid = (low + high) >> 1;
            if (nums[low] == nums[high])
            {
                while (low <= high)
                {
                    if (nums[low] < nums[mid])
                        mid = low;
                    ++low;
                }
                return nums[mid];
            }
            if (nums[mid] >= nums[low])
                low = mid;
            else if (nums[mid] <= nums[high])
                high = mid;
        }
        return nums[mid];
    }
};