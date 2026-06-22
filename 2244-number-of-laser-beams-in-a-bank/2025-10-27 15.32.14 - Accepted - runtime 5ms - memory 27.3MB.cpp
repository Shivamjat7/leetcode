class Solution {
private:  
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int m = bank[0].size();
        int total =0;
        int prev =0;
        for(int i =0;i<n;i++){
            int cnt =0;
            for(int j =0;j<m;j++){
                if(bank[i][j]=='1')cnt++;
            }
            total+= prev*cnt;
            if(cnt)prev=cnt;
        }
        return total;
    }
};