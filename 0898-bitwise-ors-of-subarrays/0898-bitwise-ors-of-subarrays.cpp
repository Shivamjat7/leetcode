class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int>ans,prev;
        for(int num:arr){
            unordered_set<int>curr;
            curr.insert(num);
            for(auto x:prev){
                curr.insert(num|x);
            }
            for(auto x:curr)ans.insert(x);
            prev = move(curr);
            
        }
        return ans.size();
    }
};