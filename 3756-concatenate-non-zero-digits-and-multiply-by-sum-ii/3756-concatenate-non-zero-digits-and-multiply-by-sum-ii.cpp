class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int MOD = 1e9 + 7;
        vector<long long> prefixSum(n + 1, 0), prefixNum(n + 1, 0),
            cnt(n + 1, 0),pow10(n+1,0);
        for (int i = 1; i <= n; i++) {
            int val = s[i - 1] - '0';
            if (val) {
                prefixSum[i] = prefixSum[i - 1] + val;
                prefixNum[i] = (prefixNum[i - 1] * 10 + val) % MOD;
                cnt[i] = cnt[i - 1] + 1;
            } else {
                prefixSum[i] = prefixSum[i - 1];
                prefixNum[i] = prefixNum[i - 1];
                cnt[i] = cnt[i - 1];
            }
        }
        vector<int> ans;
        pow10[0] = 1;
        for (int i = 1; i <= n; i++)
            pow10[i] = pow10[i - 1] * 10 % MOD;

        for (auto& q : queries) {
            int l = q[0];
            int r = q[1];
            long long sum = prefixSum[r + 1] - prefixSum[l];
            int k = cnt[r + 1] - cnt[l];
            long long x = (prefixNum[r + 1] -
                           (prefixNum[l] * pow10[k])%MOD+MOD) %
                          MOD;
            ans.push_back((sum * x) % MOD);
        }
        return ans;
    }
};