class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(!nums.size()) return 0;
        int longest=1;
        unordered_set<int> st;
        for(int val:nums) st.insert(val) ;
        for(auto it:st){
            if(st.find(it-1)== st.end()){
                int x = it;
                int cnt=1;
                while(st.find(x+1)!=st.end()){
                    x=x+1;
                    cnt++;
                }
                if(cnt>longest) longest= cnt;
            }
        }
        return longest;
        
    }
};