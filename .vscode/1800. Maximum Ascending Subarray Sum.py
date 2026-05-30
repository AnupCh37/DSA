class Solution:
    def maxAscendingSum(self, nums: List[int]) -> int:
        sum=max_sum=nums[0] 
        for i in range(1,len(nums)):
            if nums[i]>nums[i-1]:
                sum+=nums[i]
                if sum>max_sum:
                    max_sum=sum
            else:
                sum=nums[i]
        return max_sum