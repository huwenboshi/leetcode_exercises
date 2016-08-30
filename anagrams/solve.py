class Solution:
    # @param strs, a list of strings
    # @return a list of strings
    def anagrams(self, strs):
        anagram_group = dict()
        for s in strs:
            key = self.count_occ(s)
            if(key not in anagram_group):
                anagram_group[key] = []
            anagram_group[key].append(s)
        ret_list = []
        for key,val in anagram_group.items():
            if(len(val)>1):
                ret_list += val
        return ret_list

    # @param str
    # @return a string containing number of occurencce of character
    def count_occ(self, word):
        count = dict()
        for c in word:
            if(c not in count):
                count[c] = 0
            count[c] += 1
        key = ''
        for i in xrange(97, 97+26):
            c = chr(i)
            key += c
            if(c in count):
                key += str(count[c])
            else:
                key += '0'
        return key
            
        

sol = Solution()
print sol.anagrams(['hello', 'olleh', 'haha', 'ahha', 'huwenbo', 'shi'])
