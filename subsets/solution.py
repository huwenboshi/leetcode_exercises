class Solution:
    # @param S, a list of integer
    # @return a list of lists of integer
    def subsets(self, S):
        S = sorted(S)
        if(len(S) == 0):
            return [[]]
        sub = self.subsets(S[1:len(S)])
        subsets = list(sub)
        for si in sub:
            tmp = list(si)
            tmp.insert(0,S[0])
            subsets.append(tmp)
        return subsets

a = Solution()
print a.subsets([1,2])
