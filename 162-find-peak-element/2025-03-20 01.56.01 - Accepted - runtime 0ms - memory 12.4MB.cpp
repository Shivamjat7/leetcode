class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int n = nums.size();

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Ensure out-of-bounds safety by handling edge cases
            if ((mid == 0 || nums[mid] > nums[mid - 1]) && 
                (mid == n - 1 || nums[mid] > nums[mid + 1])) {
                return mid;
            }
            
            // Move the search space based on peak conditions
            if (mid > 0 && nums[mid - 1] > nums[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1; // Just in case, though we expect a peak to always exist
    }
};
