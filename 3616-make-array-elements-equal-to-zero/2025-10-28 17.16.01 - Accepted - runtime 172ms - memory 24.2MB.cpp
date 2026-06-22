class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {

                // Try both directions: 0 -> right, 1 -> left
                for (int d = 0; d < 2; d++) {
                    vector<int> arr(nums);
                    bool dir = (d == 0); // true = right, false = left
                    int curr = i;

                    while (curr >= 0 && curr < n) {
                        if (arr[curr] == 0)
                            curr += dir ? 1 : -1;
                        else {
                            arr[curr]--;
                            dir = !dir;
                            curr += dir ? 1 : -1;
                        }
                    }

                    bool valid = true;
                    for (int it : arr) {
                        if (it != 0) {
                            valid = false;
                            break;
                        }
                    }
                    if (valid) cnt++;
                }
            }
        }

        return cnt;
    }
};
