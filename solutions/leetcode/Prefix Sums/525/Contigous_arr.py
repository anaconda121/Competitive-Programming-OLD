# https://leetcode.com/problems/contiguous-array/submissions/
class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        diff = 0
        ans = 0
        repeats = {}
        for i in range(len(nums)):
            if (nums[i] == 1):
                diff -= 1
            else:
                diff += 1
                
            if (diff == 0):
                # accounts for finding balanced subset from idx 0 --> idx i
                ans = max(ans, i + 1)
            elif (diff not in repeats):
                repeats[diff] = i
            else:
                # will only occur if there are repeats[diff] already exists, meaning the same diff value has come up again
                # this means the subset from repeats[diff] --> i is balanced so the value of diff does not change
                # changes sol from O(n^2) to O(n) since eliminates need to have brute force subset checker
                ans = max(ans, i - repeats[diff])
        return ans