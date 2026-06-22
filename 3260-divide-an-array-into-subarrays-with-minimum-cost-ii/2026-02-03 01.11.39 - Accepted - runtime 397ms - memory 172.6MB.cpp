class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        multiset<int> small, large;
        long long sumSmall = 0;
        long long ans = LLONG_MAX;

        auto add = [&](int x) {
            if (small.size() < k - 1) {
                small.insert(x);
                sumSmall += x;
            } else if (!small.empty() && x < *small.rbegin()) {
                auto it = prev(small.end());
                sumSmall -= *it;
                large.insert(*it);
                small.erase(it);
                small.insert(x);
                sumSmall += x;
            } else {
                large.insert(x);
            }
        };

        auto remove = [&](int x) {
            auto it = small.find(x);
            if (it != small.end()) {
                sumSmall -= x;
                small.erase(it);
                if (!large.empty()) {
                    auto jt = large.begin();
                    sumSmall += *jt;
                    small.insert(*jt);
                    large.erase(jt);
                }
            } else {
                large.erase(large.find(x));
            }
        };

        // initial window
        for (int i = 1; i <= dist + 1 && i < n; i++) {
            add(nums[i]);
        }

        if (small.size() == k - 1)
            ans = sumSmall;

        // slide window
        for (int l = 1, r = dist + 2; r < n; l++, r++) {
            remove(nums[l]);
            add(nums[r]);
            if (small.size() == k - 1)
                ans = min(ans, sumSmall);
        }

        return nums[0] + ans;
    }
};
