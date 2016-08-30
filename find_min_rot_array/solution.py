class Solution:
    # @param num, a list of integer
    # @return an integer
    def findMin(self, num):

        # set up pointers
        # pa: first element
        # pb: last element
        pa = 0
        pb = len(num)-1

        # the case where there is no rotation
        if(num[pa] <= num[pb]):
            return num[pa]
        
        # the case where there is rotation
        return self.findMinHelper(num, pa, pb)
    
    # helper function for findMin
    def findMinHelper(self, num, pa, pb):
        if(pb-pa == 1):
            return num[pb]
        pc = int((pb+pa)/2)
        if(num[pc] > num[pa]):
            pa = pc
        else:
            pb = pc
        return self.findMinHelper(num, pa, pb)

a = Solution()
print a.findMin([2,1])
