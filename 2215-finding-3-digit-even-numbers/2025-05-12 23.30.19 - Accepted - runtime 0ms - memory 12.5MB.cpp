class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int freq[10]={0};
        vector<int> result;
        for(int i:digits){
            freq[i]++;
        }
        for(int i=100;i<999;i+=2){
            int a=i/100;
            int b=(i/10)%10;
            int c=i%10;

            int tempFreq[10]={0};
            tempFreq[a]++;
            tempFreq[b]++;
            tempFreq[c]++;
            bool isvalid=true;
            for(int d=0;d<10;d++){
                if(tempFreq[d]>freq[d]) {
                    isvalid=false;
                }

            }
            if(isvalid)result.push_back(i);

        }
        return result;
    }
};