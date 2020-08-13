class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> decompressedList;
        int frequencyPosition = 0;
        int valuePosition = 1;
        
        while(valuePosition < nums.size()){
            int frequency = nums[frequencyPosition];
            int value = nums[valuePosition];
            
            for(int i = 0; i < frequency; i++)
                decompressedList.push_back(value);
            
            frequencyPosition+=2;
            valuePosition+=2;
        }
        
       return decompressedList;
    }
};