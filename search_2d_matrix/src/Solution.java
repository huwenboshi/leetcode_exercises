public class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
    	if(matrix == null) {
    		return false;
    	}
    	
    	int num_row = matrix.length;
    	int num_col = matrix[0].length;
    	int num_cell = num_row*num_col;
    	
    	int low = 0;
    	int high = num_cell-1;
    	
    	while(low <= high) {
    		int med = (low+high)/2;
    		int i = med / num_col;
    		int j = med % num_col;
    		if(matrix[i][j] == target) {
    			return true;
    		}
    		else if(matrix[i][j] > target) {
    			high = med-1;
    		}
    		else {
    			low = med+1;
    		}
    	}
    	
        return false;
    }
    
    public static void main(String[] args) {
    	Solution sol = new Solution();
    	int[][] matrix = {{1,1}};
    	System.out.println(sol.searchMatrix(matrix, 2));
    }
}