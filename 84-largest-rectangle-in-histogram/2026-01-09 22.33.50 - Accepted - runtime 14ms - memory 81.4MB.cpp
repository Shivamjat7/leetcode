class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int mx =0;
        for(int i =0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int ht = heights[ st.top()];
                st.pop();
                int pse=st.empty()?-1:st.top();
                mx = max(mx,ht*(i-pse-1) );
            }
            st.push(i);
            
        }
        while(!st.empty()){
            int nse = heights.size();
            int ht = heights[st.top()];
            st.pop();
            int pse= st.empty()?-1:st.top();
            mx = max(mx,ht*(nse-pse-1) );
        }
        return mx;
        
    }
};