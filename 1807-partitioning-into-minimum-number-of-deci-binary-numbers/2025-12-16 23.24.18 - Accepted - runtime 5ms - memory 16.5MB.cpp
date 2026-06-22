class Solution {
public:
    int minPartitions(string n) {
        int largest =0;
        for(char ch:n){
            largest = max(largest,int(ch-'0'));
        }
        return largest;

    }
};