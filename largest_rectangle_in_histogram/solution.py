class Solution:
    # @param height, a list of integer
    # @return an integer

    def largestRectangleArea(self, height):
        n = len(height)
        if(n < 1):
            return 0

        forward = self.helper(height)
        height.reverse()
        backward = self.helper(height)
        backward =  (n-1-backward[1], n-1-backward[0])
        height.reverse()

        tmp = 0
        if(backward[0] > forward[1] or forward[0] > backward[1] or True):
            p1 = forward[0]
            p2 = forward[1]
            min_h = float('inf')
            for i in xrange(p1, p2+1):
                if(height[i] < min_h):
                    min_h = height[i]
            area1 = min_h*(p2-p1+1)
            
            p1 = backward[0]
            p2 = backward[1]
            min_h = float('inf')
            for i in xrange(p1, p2+1):
                if(height[i] < min_h):
                    min_h = height[i]
            area2 = min_h*(p2-p1+1)

            if(area1 > area2):
                tmp = area1
            else:
                tmp = area2

        p1 = forward[0]
        if(backward[0] < p1):
            p1 = backward[0]
        
        p2 = forward[1]
        if(backward[1] > p2):
            p2 = backward[1]

        min_h = float('inf')
        for i in xrange(p1, p2+1):
            if(height[i] < min_h):
                min_h = height[i]
    
        area3 = min_h*(p2-p1+1)

        if(tmp > area3):
            return tmp
        return area3

    def helper(self, height):
        p1 = 0
        p2 = 0
        cur_min_height = height[0]
        cur_max_area = height[0]
        global_max_area = height[0]

        for i in xrange(p2+1, len(height)):
            cur_height = height[i]
            if(cur_height < cur_min_height):
                cur_min_height = cur_height
            cur_area = (i-p1+1)*cur_min_height
            if(cur_area > cur_max_area):
                cur_max_area = cur_area
                p2 = i
            if(cur_height >= cur_max_area):
                cur_max_area = cur_height
                cur_min_height = cur_height
                p1 = i
                p2 = i

        return (p1, p2)


a = Solution()
#print a.largestRectangleArea([1,2,3,4,5])
#print a.largestRectangleArea([0,1,0,2,1,0,1,3,2,1,2,1])
print a.largestRectangleArea([2,0,2])
