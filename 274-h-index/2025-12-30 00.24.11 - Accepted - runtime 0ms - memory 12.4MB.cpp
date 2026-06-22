class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int h=0;
        int n = citations.size();
        for(int i=0;i<n;i++){
            h=max(h,min(citations[i],n-i));
        }
        return h;
    }
};