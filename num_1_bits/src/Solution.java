public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
    	int dist = 0;
    	int m = n;
    	int mask = 1;
    	for(int i=0; i<32; i++) {
    		if((m & mask) == 1) {
    			dist++;
    		}
    		m = m >>> 1;
    	}
        return dist;
    }
    
    public static void main(String[] args) {
    	Solution sol = new Solution();
    	System.out.println(sol.hammingWeight(1));
    }
}