#BaseballGame
class Solution:
    validOperation = list()
    #index of last valid
    past = len(validOperation)-1
    #index of last before valid
    past2 = len(validOperation)-2
    def calPoints(self, ops):
        """
        :type ops: List[str]
        :rtype: int
        """
        currentOp = None
        for index in range(0,len(ops)):
            if ops[index] == "C":
                self.validOperation.pop()
                self.updateIndex()
            elif ops[index] == "D":
                currentOp = (2*int(self.validOperation[self.past]))
                self.insertInOperands(currentOp)
            elif ops[index] == "+":
                currentOp = int(self.validOperation[self.past]) + int(self.validOperation[self.past2])
                self.insertInOperands(currentOp)
            else:
                currentOp = int(ops[index])
                self.insertInOperands(currentOp)
                
        return self.getSum()
    
    def getSum(self):
        mySum = 0
        for val in self.validOperation:
            mySum = mySum + val
        del self.validOperation[:]
        self.updateIndex()
        return mySum
    
    def insertInOperands(self, currentOp):
        self.validOperation.append(currentOp) 
        self.updateIndex()
        
    def updateIndex(self):
        self.past = len(self.validOperation)-1
        self.past2 = len(self.validOperation)-2
            