class Solution:
    def minSteps(self, D):
        target = abs(D);sum = 0;step = 0;
        
        while(sum < target or (sum-target)%2 != 0):
            step+=1;
            sum += step;
        return step;
