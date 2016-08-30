public class Solution {
    // you need treat n as an unsigned value
    public int reverseBits(int n) {
    	int n_rev = 0;
        for(int i=0; i<32; i++) {
        	int bit = (n >>> i & 1);
        	int bit_rev = bit << (31-i);
        	n_rev = n_rev | bit_rev;
        }
        return n_rev;
    }
    
    public static void main(String args[]) {
    	Solution sol = new Solution();
    	System.out.println(sol.reverseBits(43261596));
    }
}