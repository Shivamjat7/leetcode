class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            int step = nums[i] % n;        // reduce large steps
            int idx = (i + step + n) % n;  // handle negative indices
            ans[i] = nums[idx];
        }
        return ans;
    }
};