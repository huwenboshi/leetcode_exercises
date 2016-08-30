public class Solution {
    public int singleNumber(int[] A) {
        int result = 0;
        for(int i=0; i<A.length; i++) {
        	result ^= A[i];
        }
        return result;
    }
    
    public static void main(String[] args) {
    	Solution sol = new Solution();
    	int[] A = {1,2,5,2,1};
    	System.out.println(sol.singleNumber(A));
    }
}