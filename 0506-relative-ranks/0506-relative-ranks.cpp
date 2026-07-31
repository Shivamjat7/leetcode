class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<vector<int>>arr;
        for(int i =0;i<score.size();i++){
            arr.push_back({score[i],i});
        }
        sort(arr.begin(),arr.end(),[](auto a,auto b){
            return a[0]>b[0];
        });
        vector<string>ans(score.size(),"");
        for(int i =0;i<score.size();i++){
            int idx = arr[i][1];
            string temp ="";
            if(i==0){
                temp="Gold Medal";
            }else if(i==1){
                temp="Silver Medal";
            }else if(i==2){
                temp="Bronze Medal";
            }else {
                temp = to_string(i+1);
            }
            ans[idx]=temp;
        }
        return ans;
    }
};