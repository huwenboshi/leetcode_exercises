class Solution:
    # @param num, a list of integer
    # @return an integer
    def longestConsecutive(self, num):

        # create a set for num
        num_cnt = dict()
        for n in num:
            if(n not in num_cnt):
                num_cnt[n] = 0
            num_cnt[n] += 1

        # keep track of longest consecutive sequence length
        max_len = 0

        while(len(num_cnt) != 0):

            # mark numbers with 0 count for deletion
            marked = set()

            # iterate through numbers
            for n in num_cnt:

                if(num_cnt[n] == 0):
                    continue

                # current length
                cur_len = 1

                # update count
                num_cnt[n] -= 1
                if(num_cnt[n] == 0):
                    marked.add(n)
                
                # search in decreasing direction
                cur_len_inc = 0
                i = 1
                while((n-i) in num_cnt and num_cnt[n-i] > 0):
                    cur_len_inc += 1
                    num_cnt[n-i] -= 1
                    if(num_cnt[n-i] == 0):
                        marked.add(n-i)
                    i += 1

                # search in increasing direction
                cur_len_dec = 0
                i = 1
                while((n+i) in num_cnt and num_cnt[n+i] > 0):
                    cur_len_dec += 1
                    num_cnt[n+i] -= 1
                    if(num_cnt[n+i] == 0):
                        marked.add(n+i)
                    i += 1

                cur_len += cur_len_inc + cur_len_dec
               
                # update max consecutive sequence length
                if(cur_len > max_len):
                    max_len = cur_len

            # delete number with 0 count
            for m in marked:
                del num_cnt[m]
            
        return max_len

a = Solution()
print a.longestConsecutive([1,2,0,1])
