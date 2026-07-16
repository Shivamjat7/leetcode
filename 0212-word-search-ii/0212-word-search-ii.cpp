struct Node{
    vector<Node*>child;
    bool isEnd = false;
    Node(){
     child.assign(26,nullptr);
    }
};

class Solution {
private:
Node* root = new Node();
void insert(string word){
    Node* node = root;
    for(char ch:word){
        int i = ch-'a';
        if(node->child[i]==nullptr) node->child[i]=new Node();
        node = node->child[i];

    }
    node->isEnd = true;
}
public:
    string temp;
    vector<string>ans;
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    int n,m;
    void  find(int i ,int j,Node* node,vector<vector<char>>&board,vector<vector<bool>>&vis){
        if(!node)return;
        temp.push_back(board[i][j]);
        if(node->isEnd){
            ans.push_back(temp);
            node->isEnd = false;
        }
        vis[i][j]=true;
        for(int p=0;p<4;p++){
            int row = i+dr[p];
            int col = j+dc[p];
            if(row>=0 && row<n && col>=0 && col<m && !vis[row][col]){
                int index = board[row][col]-'a';
                
                find(row,col,node->child[index],board,vis);
            }
        }
        vis[i][j]=false;
        temp.pop_back();
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n= board.size();
        m = board[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(auto word:words) insert(word);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]){
                    int index = board[i][j]-'a';
                    find(i,j,root->child[index],board,vis);
                }
            }
        }
        return ans;

    }
};