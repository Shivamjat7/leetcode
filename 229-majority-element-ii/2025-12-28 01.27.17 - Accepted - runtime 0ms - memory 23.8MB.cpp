class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1 = 0, c2 = 0;
        int e1 = INT_MIN, e2 = INT_MIN;

        // 1st pass: find candidates
        for (int x : nums) {
            if (x == e1) c1++;
            else if (x == e2) c2++;
            else if (c1 == 0) {
                e1 = x; c1 = 1;
            }
            else if (c2 == 0) {
                e2 = x; c2 = 1;
            }
            else {
                c1--; c2--;
            }
        }

        // 2nd pass: verify
        c1 = c2 = 0;
        for (int x : nums) {
            if (x == e1) c1++;
            else if (x == e2) c2++;
        }

        vector<int> ans;
        if (c1 > nums.size() / 3) ans.push_back(e1);
        if (c2 > nums.size() / 3) ans.push_back(e2);

        return ans;
    }
};
