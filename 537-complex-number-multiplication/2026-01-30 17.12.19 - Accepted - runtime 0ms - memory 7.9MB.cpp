class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        string a = "";
        string b ="";
       int i=0;
       while(i<num1.size()){
        if(num1[i]!='+')a+=num1[i];
        else break;
        i++;
       }
       i++;
        while(i<num1.size()){
        if(num1[i]!='i')b+=num1[i];
        else break;
        i++;
       }
          string c = "";
        string d ="";
        i=0;
       while(i<num2.size()){
        if(num2[i]!='+')c+=num2[i];
        else break;
        i++;
       }
       i++;
        while(i<num2.size()){
        if(num2[i]!='i')d+=num2[i];
        else break;
        i++;
       }
       int real = stoi(a)*stoi(c) -stoi(b)*stoi(d);
       int imag = stoi(a)*stoi(d)+stoi(c)*stoi(b);
       return to_string(real)+'+'+to_string(imag)+'i';
    }
};