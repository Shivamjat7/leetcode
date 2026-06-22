class Solution {
public:
    string getPermutation(int n, int k) {
        int fact  =1;
        vector<int>nums ;
        for(int i =1;i<n;i++){
            fact =fact*i;
            nums.push_back(i);
        }
        nums.push_back(n);
        k = k-1;
        string ans ="";
        while(nums.size()){
            ans =ans+ to_string(nums[k/fact]);
            nums.erase(nums.begin()+k/fact);
            k  = k%fact;
          if(nums.size())  fact = fact/nums.size();
        }
        return ans;
    }
};