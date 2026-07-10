class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        sort(sides.begin(),sides.end());
        int a = sides[0];
        int b = sides[1];
        int c = sides[2];
        if(c>=a+b)return {};
    
         double A = acos((b*b + c*c - a*a) / (2.0*b*c));
        double B = acos((a*a + c*c - b*b) / (2.0*a*c));
        double C = acos((a*a + b*b - c*c) / (2.0*a*b));

        auto degree =[](double radian){return radian *180.0/acos(-1.0);};
        vector<double>ans = {degree(A),degree(B),degree(C)};
        sort(ans.begin(),ans.end());
        return ans;


    }
};