class Solution:
    # @param num, a list of integer
    # @return an integer
    def findMin(self, num):

        # set up pointers
        # pa: first element
        # pb: last element
        pa = 0
        pb = len(num)-1

        if(len(num) == 1):
            return num[0]

        if(num[pb] > num[pa]):
            return num[pa]

        # the case where there is rotation
        return self.findMinHelper(num, pa, pb)
    
    # helper function for findMin
    def findMinHelper(self, num, pa, pb):
        if(pb-pa == 1 or pa-pb == 1):
            if(num[pb] > num[pa]):
                return num[pa]
            return num[pb]
        pc = int((pb+pa)/2)
        if(num[pc] != num[pa]):
            if(num[pc] > num[pa]):
                pa = pc
            else:
                pb = pc
            return self.findMinHelper(num, pa, pb)
        else:
            r1 = self.findMinHelper(num, pc, pb)
            r2 = self.findMinHelper(num, pa, pc)
            if(r1 > r2):
                return r2
            return r1

a = Solution()
print a.findMin([4,5,6,7,0,1,2])
