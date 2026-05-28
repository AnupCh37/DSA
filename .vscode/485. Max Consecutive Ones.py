class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        ans=count=0
        for i in range(len(nums)):
            if(nums[i]==1):
                count+=1
            else: 
              count=0
            if count>ans:  
              ans=count
        return ans