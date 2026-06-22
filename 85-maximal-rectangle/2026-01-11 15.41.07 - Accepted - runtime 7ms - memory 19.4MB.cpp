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
    int maximalRectangle(vector<vector<char>>& matrix) {
    int n =matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> pref(n,vector<int>(m,0));
     for(int j =0;j<m;j++){
        int sum =0;
        for(int i=0;i<n;i++){
            sum+=1;
            if( matrix[i][j]=='0')sum =0;
            pref[i][j]=sum;
        }
     }
     int mxArea=0;
     for(int i=0;i<n;i++){
        int area = largestRectangleArea(pref[i]);
        mxArea=max(mxArea,area);
     }
     return mxArea;
    }
};