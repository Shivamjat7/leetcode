class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int>v1;
        string str="";
        for(char ch:version1){
            if(ch=='.'){
                v1.push_back(stoi(str));
                str="";
            }else{
                str+=ch;
            }
        }
        v1.push_back(stoi(str));
        str="";
        int i=0;
        for(char ch:version2){
            if(ch=='.'){
                int num1= i<v1.size()?v1[i++]:0;
                int num2 =stoi(str);
                if(num1>num2)return 1;
                if(num2>num1)return -1;
                str="";
            }else{
                str+=ch;
            }
        }
        int num1= i<v1.size()?v1[i++]:0;
        int num2 =stoi(str);
        if(num1>num2)return 1;
        if(num2>num1)return -1;
        while(i<v1.size()){
            if(v1[i]>0)return 1;
            i++;
        }
        return 0;
       
    }
};