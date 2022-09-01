class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        dup_count = 0
        for i in range(len(nums)):
            # print(i, nums)
            i -= dup_count 
            if (nums.count(nums[i]) > 1):
                #0:2 and 1:2
                nums[i:len(nums)] = nums[i+1:len(nums)]
                dup_count += 1
                #print("remove dup", i, nums)
                
        return len(nums)
