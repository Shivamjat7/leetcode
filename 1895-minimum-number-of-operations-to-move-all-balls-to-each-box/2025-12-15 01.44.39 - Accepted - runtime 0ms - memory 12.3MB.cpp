class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n, 0);

        int count = 0, ops = 0;
        // left to right
        for (int i = 0; i < n; i++) {
            ans[i] += ops;
            count += (boxes[i] == '1');
            ops += count;
        }

        count = 0;
        ops = 0;
        // right to left
        for (int i = n - 1; i >= 0; i--) {
            ans[i] += ops;
            count += (boxes[i] == '1');
            ops += count;
        }

        return ans;
    }
};
