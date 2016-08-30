class Solution:
    # @param num, a list of integer
    # @return a list of lists of integers
    def permuteUnique(self, num):
        n = len(num)
        if(n == 0):
            return [[]]
        sub = self.permuteUnique(num[1:len(num)])
        all_per = []
        all_per_set = set()
        for p in sub:
            for i in xrange(len(p)+1):
                q = list(p)
                q.insert(i, num[0])
                per_str = ';'.join([str(qi) for qi in q])
                if(per_str not in all_per_set):
                    all_per.append(q)
                    all_per_set.add(per_str)
        return all_per

num = []
a = Solution()
p = a.permuteUnique(num)
print p
print len(p)
