class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            int cnt=0;
            while(!st.empty() && heights[i]>heights[st.top()]){
                 cnt++;
                st.pop();
            };
            if(st.empty()) ans[i]=cnt;
            else ans[i]=cnt+1;
            ;
            st.push(i);
        }
       return ans;
        
    }
};