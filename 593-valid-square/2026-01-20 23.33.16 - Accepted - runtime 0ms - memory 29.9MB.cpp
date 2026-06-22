class Solution {
public:
    double dist(vector<int>& p1,vector<int>&p2){
        int x= p1[0],y=p1[1];
        int a=p2[0],b =p2[1];
        int X=(x-a);
        int Y=(y-b);
        return X*X+Y*Y;
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
       vector<vector<int>> p ={p1,p2,p3,p4};
       vector<int>d;
       for(int i=0;i<4;i++){
        for(int j=i+1;j<4;j++){
            d.push_back(dist(p[i],p[j]));
        }
       }
         sort(d.begin(), d.end());

        return d[0] > 0 &&
               d[0] == d[1] &&
               d[1] == d[2] &&
               d[2] == d[3] &&      
               d[4] == d[5] &&    
               d[4] == 2 * d[0];   


    }
};