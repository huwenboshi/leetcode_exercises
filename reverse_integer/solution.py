class Solution:
    # @return an integer
    def reverse(self, x):
        neg = False
        if(x < 0):
            neg = True
            x = -x
        digits = []
        while(x != 0):
            d = x % 10
            digits.append(d)
            x = int(x/10)
        y = 0
        b = 1
        for i in xrange(len(digits)):
            d = digits[len(digits)-1-i]
            y += d*b
            b = b*10
        if(y > 2**31):
            return 0
        if(neg):
            return -y
        return y

a = Solution()
print a.reverse(1534236469)
