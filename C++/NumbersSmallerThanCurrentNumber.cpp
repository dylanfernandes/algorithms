struct ArrayNumber
{
    int value;
    int index;

    ArrayNumber(int value, int index) : value(value), index(index) {}
};

struct less_than_value
{
    inline bool operator() (const ArrayNumber& arrayNumber1, const ArrayNumber& arrayNumber2)
    {
        return (arrayNumber1.value < arrayNumber2.value);
    }
};

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> results(nums.size());
        vector<ArrayNumber> sortingContainer;
        
        for(int i = 0; i < nums.size(); i++) 
            sortingContainer.push_back(ArrayNumber(nums[i],i)); 
        
        sort(sortingContainer.begin(),sortingContainer.end(), less_than_value());
        
        for(int i = 0; i < sortingContainer.size();i++) { 
            int prev = i - 1;
            int resultIndex = sortingContainer[i].index;
            
            if(prev < 0)
                results.at(resultIndex) = 0;
            else {
                if(sortingContainer[i].value == sortingContainer[prev].value) {
                    int prevResult = results.at(sortingContainer[prev].index);
                    results.at(resultIndex) = prevResult;
                } 
                else
                    results.at(resultIndex) = i; 
            }
        }
        
        return results;
    }
};