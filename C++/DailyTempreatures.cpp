class LookAhead {
    private:
        int start;
        int size;
        int end;
        int max;
    public:
        LookAhead(int start, int size, vector<int> numbers){
            this->start = start;
            this->size = size;
            if(start + size <= numbers.size())
                this->end = start + size;
            else
                this->end = numbers.size();
            this->max = 0;
            for(int i = start; i < end;i++) {
                if(numbers[i] > max)
                    max = numbers[i];
            }
        }
        
        int getHigherLocation(int value) {
            for(int i = start; i < end;i++) {
                if(numbers[i] > value)
                    return i;
            }
            return -1;
        }
    
        int getMax() {
            return max;
        }
        
        int getEnd() {
            return end;
        }
    
        bool isInRange(int location){
            return location >= start && location <= end;
        }
    
}

class LookAheadBank {
    private: 
        vector<LookAhead> lookAheads;
        int lookAheadDistance = 20;
        vector<int> numbers;
        int lookAheadIndex = -1;
    
        LookAhead getCurrentLookAhead(int currentIndex) {
            if(lookAheadIndex == -1 || (!currentLookAhead.isInRange(currentIndex) && lookAheadIndex == lookAheads.size()-1)){
                LookAhead currentLookAhead = LookAhead(currentIndex, lookAheadDistance, numbers);
                lookAheads.push_back(currentLookAhead);
                lookAheadIndex = lookAheads.size()-1;
            } else if(lookAheadIndex != lookAheads.size()-1)
                lookAheadIndex++;
            return lookAheads[lookAheadIndex];
        }
    public:
        LookAheadBank(vector<int> numbers) {
            this->numbers = numbers;
        }
    
        int getHigherNumberLocation(int currentIndex){
            LookAhead currentLookAhead = getCurrentLookAhead(currentIndex);
            int computationIndex = currentIndex;
            if(currentLookAhead.getMax() < numbers[currentIndex]) {
                while(currentLookAhead.getMax() < numbers[currentIndex]) {
                    int nextStart = currentLookAhead.getEnd() + 1;
                    currentLookAhead = LookAhead(nextStart, lookAheadDistance, numbers);
                    lookAheads.push_back(currentLookAhead);
                    computationIndex = lookAheads.size()-1;
                }
            }
            else
                currentLookAhead.getHigherLocation(currentIndex);
            
        }
}

class Solution {
    public:
        vector<int> dailyTemperatures(vector<int>& T) {
            vector<int> daysToWait;
            for(int currentPointer = 0;currentPointer < T.size();currentPointer++){
                int currentTempreature = T[currentPointer];
                int futurePointer;
            
                for(futurePointer = currentPointer; futurePointer < T.size(); futurePointer++)
                    if(T[futurePointer] > T[currentPointer]) {
                        daysToWait.push_back(futurePointer-currentPointer);
                        break;
                    }
                if(futurePointer == T.size())
                    daysToWait.push_back(0);
            }
        
        return daysToWait; 
    }
};