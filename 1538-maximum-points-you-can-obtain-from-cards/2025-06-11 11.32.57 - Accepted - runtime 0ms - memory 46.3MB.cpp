class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0;
        int n=cardPoints.size();
        for(int i=0;i<k;i++){
            sum+=cardPoints[i];
        }
        int maxPoints =sum;
        for(int i =k-1;i>=0;i--){
            sum=sum-cardPoints[i];
            sum=sum+ cardPoints[--n];
            maxPoints=max(sum,maxPoints);
        }
        return maxPoints;

    }
};