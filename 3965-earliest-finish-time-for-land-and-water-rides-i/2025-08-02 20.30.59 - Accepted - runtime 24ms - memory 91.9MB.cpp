class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {

        int minFinish = INT_MAX;
        for(int i =0 ; i< landStartTime.size();i++){
            for( int  j =0 ;j< waterStartTime.size();j++){

                int landStart = landStartTime[i];
                int landEnd = landStart + landDuration[i];
                int waterStart = max(landEnd,waterStartTime[j]);
                int waterEnd = waterStart + waterDuration[j];
                minFinish = min(minFinish,waterEnd);


                waterStart = waterStartTime[j];
                waterEnd = waterStart + waterDuration[j];
                landStart = max(waterEnd,landStartTime[i]);
                landEnd = landStart + landDuration[i];
                minFinish = min(minFinish, landEnd);
                
                
            }
        }
        return minFinish;
    }
};