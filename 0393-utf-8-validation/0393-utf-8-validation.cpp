class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int remaining =0;
        for(int &byte :data){
            byte&=0xFF;
            if(remaining==0){
                if((byte&0x80) ==0)continue;
                else if((byte& 0xE0) ==0xC0) remaining =1;
                else if((byte & 0xF0) == 0xE0)remaining =2;
                else if((byte & 0xF8) == 0xF0)remaining =3;
                else return false;
            } else{
                if((byte&0xC0)!=0x80)return false;
                remaining --;
            }
        }
        return remaining ==0;
    }
};