class Solution:
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s) != len(t) return False

        for x, y in zip(s, t):
            if s.find(x) != t.find(y):
                return False

        return True


if __name__ == "__main__":
    Solution().isIsomorphic("ab", "ca")
