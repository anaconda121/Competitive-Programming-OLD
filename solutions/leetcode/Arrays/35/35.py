class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        if (nums.count(target) == 0): # target not found
            for i in range(len(nums)):
                if (nums[i] > target):
                    return i
            return len(nums)
        else:
            return nums.index(target)
