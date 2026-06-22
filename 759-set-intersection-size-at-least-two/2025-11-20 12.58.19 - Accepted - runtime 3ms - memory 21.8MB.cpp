class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](auto& a, auto & b){
            if(a[1]==b[1]) return a[0]>b[0];
            else return a[1]<b[1];
        });
        int p1=-1,p2=-1;
        int ans =0;
        for(auto & in:intervals){
            int l = in[0],r= in[1];
            bool c1 =(p1>=l && p1<=r);
            bool c2 =(p2>=l && p2<=r);
            if(c1 && c2) continue;
            if(c2){
                ans++;
                p1=p2;
                p2 =r;
            }else{
                ans+=2;
                p1=r-1;
                p2=r;
            }

        }
    return ans;
    }
};