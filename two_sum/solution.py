class Solution:
    # @return a tuple, (index1, index2)
    def twoSum(self, num, target):
        num_idx = dict()
        for i in xrange(len(num)):
            num_idx[num[i]] = i
        for i in xrange(len(num)):
            res = target-num[i]
            if(res in num_idx and num_idx[res] != i):
                return (i+1, num_idx[res]+1)
        return (0,0)

a = Solution()
print a.twoSum([3,2,4], 6)
