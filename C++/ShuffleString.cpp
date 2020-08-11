class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        vector<char> shuffleResult(indices.size(), ' ');
        
        for(int i = 0;i < indices.size();i++){
            int currentLocation = indices[i];
            char currentChar  = s.at(i);
            shuffleResult[currentLocation] = currentChar;
        }
        
        return string(shuffleResult.begin(), shuffleResult.end());
    }
};