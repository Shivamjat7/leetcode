class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        vector<int> ans={-1,-1,-1};
        int xc=center[0],yc=center[1];
        for(auto tower:towers){
            int x =tower[0];
            int y =tower[1];
            int q = tower[2];
            int dist =abs(x-xc)+abs(y-yc);
            if(dist<=radius){
                if(q>ans[2]){
                    ans={x,y,q};
                }else if(q==ans[2]){
                    if(x<ans[0]){
                       ans={x,y,q}; 
                    }else if( x==ans[0]&& y<ans[1]){
                        ans={x,y,q}; 
                    }
                }
            }
        }
        vector<int>res={ans[0],ans[1]};
        return res;
        
    }
};