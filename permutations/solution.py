class Solution:
    # @param num, a list of integer
    # @return a list of lists of integers
    def permute(self, num):
        n = len(num)
        if(n == 0):
            return [[]]
        sub = self.permute(num[1:len(num)])
        all_per = []
        for p in sub:
            for i in xrange(len(p)+1):
                q = list(p)
                q.insert(i, num[0])
                all_per.append(q)
        return all_per

num = [1,2,3,4]
a = Solution()
p = a.permute(num)
print p
print len(p)
