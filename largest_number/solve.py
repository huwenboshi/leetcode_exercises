class Solution:
    # @param num, a list of integers
    # @return a string
    def largestNumber(self, numbers):
        numbers_str = [str(num) for num in numbers]
        print sorted(numbers_str)

sol = Solution()
print sol.largestNumber([3,30,34,5,9])
