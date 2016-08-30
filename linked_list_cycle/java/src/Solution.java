class ListNode {
    int val;
    ListNode next;
    ListNode(int x) {
        val = x;
        next = null;
    }
}
 
public class Solution {
    public boolean hasCycle(ListNode head) {
    	
    	ListNode ptr1 = head;
    	ListNode ptr2 = head == null ? null : head.next;
    	
    	while(true) {
    		if(ptr1 == null || ptr2 == null) {
    			return false;
    		}
    		else if(ptr1 == ptr2) {
    			return true;
    		}
    		
    		ptr1 = ptr1 == null ? null : ptr1.next;
    		ptr2 = ptr2 == null ? null : ptr2.next;
    		ptr2 = ptr2 == null ? null : ptr2.next;
    	}
    	
    }
    
    public static void main(String[] args) {
    	ListNode head1_n1 = new ListNode(1);
    	ListNode head1_n2 = new ListNode(2);
    	ListNode head1_n3 = new ListNode(3);
    	ListNode head1_n4 = new ListNode(4);
    	head1_n1.next = head1_n2;
    	head1_n2.next = head1_n3;
    	head1_n3.next = head1_n4;
    	head1_n4.next = head1_n1;
    	
    	Solution sol = new Solution();
    	System.out.println(sol.hasCycle(null));
    }
}