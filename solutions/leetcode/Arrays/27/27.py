class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        n_removed = 0
        for i in range(len(nums)):
            i -= n_removed
            if (nums[i] == val):
                nums.remove(nums[i])
                n_removed += 1
        return len(nums)
