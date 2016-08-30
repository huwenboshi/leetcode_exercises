class Solution:
    # @return an integer
    def minDistance(self, word1, word2):
       
        # empty string condition
        if(word1 == ''):
            return len(word2)
        if(word2 == ''):
            return len(word1)

        # create table
        len1 = len(word1)
        len2 = len(word2)
        table = [[0]*(len1+1) for i in xrange(len2+1)]

        # init table
        for i in xrange(0, len1+1):
            table[0][i] = i
        for i in xrange(0, len2+1):
            table[i][0] = i

        # fill table
        for i in xrange(1, len2+1):
            for j in xrange(1, len1+1):
                val = self.fill_cell(table, i, j, word1, word2)
                table[i][j] = val
        
            #self.print_table(table)
            #print

        # return minimum edit distance
        return table[len2][len1]

    # @return the integer to be filled at a cell  with index i and j
    def fill_cell(self, table, i, j, word1, word2):
        val1 = table[i-1][j]
        val2 = table[i][j-1]
        val3 = table[i-1][j-1]
        
        if(word1[j-1] == word2[i-1]):
            return val3
        else:
            return self.min3(val1+1, val2+1, val3+1)

    # @ return the minimum of 3 values
    def min3(self, a, b, c):
        return min(min(a,b),c)
    
    # @ print table for debugging
    def print_table(self, table):
        for i in xrange(len(table)):
            line = ' '.join([str(c) for c in table[i]])
            print line

sol = Solution()
print sol.minDistance('halo', 'hello')
