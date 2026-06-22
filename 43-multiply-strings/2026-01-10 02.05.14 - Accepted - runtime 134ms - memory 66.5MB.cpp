class Solution {
public:
    string m(string num,int x){
        if(num=="0"||x==0)return "0";
        string res="";
        int carry=0;
        for(int i=num.size()-1;i>=0 ;i--){
                int n=num[i]-'0';
                int prod = n*x;
                prod+=carry;
                carry=prod/10;
                char d = prod%10+'0';
                res=d+res;
                
        }
        if(carry){ res= char(carry+'0')+res;}
        return res;
    }
    string add(string num1,string num2){
        int i=num1.size()-1;
        int j=num2.size()-1;
        string res ="";
        int carry =0;
        while(i>=0 && j>=0){
            int a = num1[i]-'0';
            int b = num2[j]-'0';
            int sum = a+b+carry;
            carry=sum/10;
            sum=sum%10;
            res= char(sum+'0')+res; 
            i--;
            j--;
        }
        while(i>=0){
            int a = num1[i]-'0';
            int sum = a+carry;
            carry=sum/10;
            sum=sum%10;
            res= char(sum+'0')+res; 
            i--;
        }
        while(j>=0){
            int b = num2[j]-'0';
            int sum = b+carry;
            carry=sum/10;
            sum=sum%10;
            res= char(sum+'0')+res; 
            j--;
        }
        if(carry) res= char(carry+'0')+res;
        return res;

    }
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0")return "0";
        string res ="";
        int z=0;
        for(int i=num2.size()-1;i>=0;i--){
            string p = m(num1,num2[i]-'0');
            p.append(z,'0');
            res=add(p,res);
            z++;
        }
        return res;
    }
};