class Solution {
public:
    string defangIPaddr(string address) {
        string defangedAddress = "";
        for(int i = 0;i < address.length();i++) {
            char currentChar =  address.at(i);
            if(currentChar == '.')
                defangedAddress += "[.]";
            else
                defangedAddress += currentChar;
        }
        
        return defangedAddress;
    }
};