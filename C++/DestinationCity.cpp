class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string, int> possibilities;
        
        for(int flight = 0; flight < paths.size(); flight++) {
            for(int locationType = 0; locationType < paths[flight].size(); locationType++) {
                string currentLocation = paths[flight][locationType];
                map<string, int>::iterator i = possibilities.find(currentLocation);
                if(i == possibilities.end() || locationType == 0)
                    possibilities[currentLocation] = locationType;
            }
        }
        
       string key = "";
       for (auto &i : possibilities) {
          if (i.second == 1) {
             key = i.first;
             break;
          }
       }
        return key;
    }
};