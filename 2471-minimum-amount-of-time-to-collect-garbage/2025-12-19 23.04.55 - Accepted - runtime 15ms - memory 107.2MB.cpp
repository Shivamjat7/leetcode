class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        int total = 0;

        int lastM = -1, lastP = -1, lastG = -1;

        // Count garbage and record last occurrence
        for (int i = 0; i < n; i++) {
            for (char ch : garbage[i]) {
                total++; // pickup time
                if (ch == 'M') lastM = i;
                else if (ch == 'P') lastP = i;
                else if (ch == 'G') lastG = i;
            }
        }

        // Prefix sum of travel
        for (int i = 1; i < n-1; i++) {
            travel[i] += travel[i - 1];
        }

        if (lastM > 0) total += travel[lastM - 1];
        if (lastP > 0) total += travel[lastP - 1];
        if (lastG > 0) total += travel[lastG - 1];

        return total;
    }
};
