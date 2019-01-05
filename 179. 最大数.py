from functools import cmp_to_key


def cmp(a, b):
    if a + b > b + a:
        return 1
    elif a + b < b + a:
        return -1
    else:
        return 0




class Solution:
    def largestNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        result = ''.join(sorted(map(str, nums), key=cmp_to_key(cmp), reverse=True))
        return result[:-1].lstrip('0') + result[-1]
