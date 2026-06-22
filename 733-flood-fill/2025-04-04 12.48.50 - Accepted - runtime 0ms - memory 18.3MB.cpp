class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int original = image[sr][sc];
        if(original==color)return image;
        int m= image[0].size();
        int n = image.size();
        queue<pair<int,int>> q;
        q.push({sr,sc});
        
        
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            image[i][j]=color;
            q.pop();


            if(j<m-1 && image[i][j+1]==original && image[i][j+1] !=color){
                q.push({i,j+1});
            }
            if(j>0 && image[i][j-1]==original && image[i][j-1] !=color){
                q.push({i,j-1});
            }
            if(i<n-1 && image[i+1][j]==original && image[i+1][j] !=color){
                q.push({i+1,j});
            }
            if(i>0 && image[i-1][j]==original && image[i-1][j] !=color){
                q.push({i-1,j});
            }
        }
        
        return image;

        
    }

};