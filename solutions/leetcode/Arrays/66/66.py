class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        num = ""
        for i in range(len(digits)):
            num += str(digits[i])
        num = int(num) + 1

        li = []
        for i in range(len(str(num))):
            li.append(int(str(num)[i]))
        return li
