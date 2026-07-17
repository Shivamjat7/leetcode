class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>ans;
        vector<string>line;
        int len =0;
        for(int i=0;i<words.size();i++){
            if(len+line.size()+words[i].size()<=maxWidth){
                len += words[i].size();
                line.push_back(words[i]);
            }else{
                int rem = maxWidth-len;
                int gap = line.size()-1;
                string temp= line[0];
                for(int j =1;j<line.size();j++){
                    int cut =ceil(1.0*rem/gap);
                    rem-=cut;
                    gap--;
                    while(cut-->0) temp+=" ";
                    temp+=line[j];
                }
                while(rem-->0)temp+=" ";
                ans.push_back(temp);
                line.clear();
                line.push_back(words[i]);
                len = words[i].size();

            }
          
           
            
        }   if(line.size()>0){
            string temp=line[0];
            int rem = maxWidth-len;
            for(int i =1;i<line.size();i++){
                temp+=" ";
                temp+= line[i];
                rem--;
            }
            while(rem-->0)temp+=" ";
            ans.push_back(temp);
          }
          
        return ans;
    }
};