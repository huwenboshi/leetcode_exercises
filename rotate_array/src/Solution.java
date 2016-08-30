public class Solution {
	public void shift(int[] nums) {
		int last = nums[nums.length-1];
		for(int i=nums.length-1; i>=1; i--) {
			nums[i] = nums[i-1];
		}
		nums[0] = last;
	}
	
    public void rotate(int[] nums, int k) {
    	int k2 = k%nums.length;
    	for(int i=0; i<k2; i++) {
    		shift(nums);
    	}
    }
    
    public static void main(String[] args) {
    	int[] nums = {1,2,3,4};
    	Solution sol = new Solution();
    	sol.rotate(nums, 2);
    	for(int i=0; i<nums.length; i++) {
    		System.out.println(nums[i]);
    	}
    }
}