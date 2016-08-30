public class Solution {
    public int majorityElement(int[] num) {
    	int major_val = num[0];
    	int major_cnt = 1;
        
        for(int i=1; i<num.length; i++) {
        	if(num[i] == major_val) {
        		major_cnt++;
        	}
        	else {
        		major_cnt--;
        	}
        	if(major_cnt == 0) {
        		major_val = num[i];
        		major_cnt = 1;
        	}
        }
        
        return major_val;
    }
    
    public static void main(String[] args) {
    	Solution sol = new Solution();
    	int[] num = {1,2,3,2,4,2,2};
    	System.out.println(sol.majorityElement(num));
    } 
}